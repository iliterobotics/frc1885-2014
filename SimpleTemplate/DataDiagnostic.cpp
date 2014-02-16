#include "DataDiagnostic.h"
#include "DigitalModule.h"
#include "AnalogModule.h"
#include "DriverStation.h"
#include "Joystick.h"
#include "Utility.h"

RobotTelemetry::RobotTelemetry() {
	isEnabled = false;
	robotDiagnostics = new RobotTelemetryData();
	mRobotTelemetry = semBCreate(SEM_Q_FIFO,SEM_FULL);
	startTime = GetFPGATime();
	initTelemetryData();
}

RobotTelemetry::~RobotTelemetry() {
	delete robotDiagnostics;
}

void RobotTelemetry::initTelemetryData() {
	unsigned int index;

	unsigned int buttonIndex;

	robotDiagnostics->time = 0;
	
	//robotDiagnostics->batteryVoltage = 0;

	for(index = 0; index < sizeof(robotDiagnostics->pwmOutputs)/sizeof(*robotDiagnostics->pwmOutputs); index++) {
		robotDiagnostics->pwmOutputs[index] = 0;
	}

	for(index = 0; index < sizeof(robotDiagnostics->relayOutputs)/sizeof(*robotDiagnostics->relayOutputs); index++) {
		robotDiagnostics->relayOutputs[index] = 0;
	}

	for(index = 0; index < sizeof(robotDiagnostics->digitalInputs)/sizeof(*robotDiagnostics->digitalInputs); index++) {
		robotDiagnostics->digitalInputs[index] = 0;
	}

	for(index = 0; index < sizeof(robotDiagnostics->analogInputs)/sizeof(*robotDiagnostics->analogInputs); index++) {
		robotDiagnostics->analogInputs[index] = 0;
	}

	for(index = 0; index < sizeof(robotDiagnostics->pneumatics)/sizeof(*robotDiagnostics->pneumatics); index++) {
		robotDiagnostics->pneumatics[index] = 0;
	}

	for(index = 0; index < sizeof(robotDiagnostics->joysticks)/sizeof(*robotDiagnostics->joysticks); index++) {
		robotDiagnostics->joysticks[index].x = 0;
		robotDiagnostics->joysticks[index].y = 0;
		robotDiagnostics->joysticks[index].z = 0;

		for(buttonIndex = 0; buttonIndex < 8; buttonIndex++) {
			robotDiagnostics->joysticks[index].buttons[buttonIndex] = 0;
		}
	}

	for(index = 0; index < sizeof(robotDiagnostics->gamepads)/sizeof(*robotDiagnostics->gamepads); index++) {
		robotDiagnostics->gamepads[index].x = 0;
		robotDiagnostics->gamepads[index].y = 0;
		robotDiagnostics->gamepads[index].z = 0;

		for(buttonIndex = 0; buttonIndex < 8; buttonIndex++) {
			robotDiagnostics->gamepads[index].buttons[buttonIndex] = 0;
		}
	}

}

int RobotTelemetry::getId() {
	return id;
}

/*
 * Get the length
 */
long RobotTelemetry::getLength() {
	return sizeof(*robotDiagnostics);
}

/*
 * Encode this data structure into a byte array
 */
char* RobotTelemetry::getEncoded() {
	//[time][pwms][relays][dio][aio][pnio][joysticks][gamepads]
    char* diagnosticBuffer = reinterpret_cast<char*>(robotDiagnostics);
 
	return diagnosticBuffer;
}

RobotTelemetryData* RobotTelemetry::getDecoded(char* encodedBytes) {
	RobotTelemetryData* diag = reinterpret_cast<RobotTelemetryData*>(encodedBytes);
	return diag;
}

void RobotTelemetry::enable() {
	if(!isEnabled) {
		semTake(mRobotTelemetry,WAIT_FOREVER);
        isEnabled = true;
		semGive(mRobotTelemetry);

		taskSpawn ("RobotTelemetry", 101, 0, 20000, (FUNCPTR)RobotTelemetry::start,(int)this,0,0,0,0,0,0,0,0,0);
	}
}

void RobotTelemetry::disable() {
	semTake(mRobotTelemetry,WAIT_FOREVER);
    isEnabled = false;
	semGive(mRobotTelemetry);
}

void RobotTelemetry::updateSendRate(long rate) {
	
	bool wasEnabled = isEnabled;
	
	//disable
	disable();
	
	//update the rate
	semTake(mRobotTelemetry,WAIT_FOREVER);
	sendRate = rate;
	semGive(mRobotTelemetry);
	
	//enable
	if(wasEnabled) {
		enable();
	}
}

void RobotTelemetry::updateTelemetryData() {
	unsigned int buttonIndex = 0;
	unsigned int index = 0;
	DigitalModule* dio = DigitalModule::GetInstance(1);
	AnalogModule* aio = AnalogModule::GetInstance(1);
	
	//micro seconds to milliseconds
	robotDiagnostics->time = (long)((GetFPGATime() - startTime) * 1.0e-3);
	
	//robotDiagnostics->batteryVoltage = DriverStation::GetInstance()->GetBatteryVoltage();
	
	for(index = 0; index < sizeof(robotDiagnostics->pwmOutputs)/sizeof(*robotDiagnostics->pwmOutputs); index++) {
		robotDiagnostics->pwmOutputs[index] = dio->GetPWM(index+1);
	}

	for(index = 0; index < sizeof(robotDiagnostics->relayOutputs)/sizeof(*robotDiagnostics->relayOutputs); index++) {
		robotDiagnostics->relayOutputs[index] = (dio->GetRelayForward(index+1) ? 1 : (dio->GetRelayReverse(index+1) ? 1 : 0));
	}

	for(index = 0; index < sizeof(robotDiagnostics->digitalInputs)/sizeof(*robotDiagnostics->digitalInputs); index++) {
		robotDiagnostics->digitalInputs[index] = dio->GetDIO(index+1);
	}

	for(index = 0; index < sizeof(robotDiagnostics->analogInputs)/sizeof(*robotDiagnostics->analogInputs); index++) {
		robotDiagnostics->analogInputs[index] = aio->GetAverageVoltage(index+1);
	}

	for(index = 0; index < sizeof(robotDiagnostics->pneumatics)/sizeof(*robotDiagnostics->pneumatics); index++) {
		robotDiagnostics->pneumatics[index] = 0;
	}
	
	for(index = 0; index < sizeof(robotDiagnostics->joysticks)/sizeof(*robotDiagnostics->joysticks); index++) {
		robotDiagnostics->joysticks[index].x = Joystick::GetStickForPort(index+1)->GetAxis(Joystick::kXAxis);
		robotDiagnostics->joysticks[index].y = Joystick::GetStickForPort(index+1)->GetAxis(Joystick::kYAxis);
		robotDiagnostics->joysticks[index].z = Joystick::GetStickForPort(index+1)->GetAxis(Joystick::kZAxis);

		for(buttonIndex = 0; buttonIndex < 8; buttonIndex++) {
			robotDiagnostics->joysticks[index].buttons[buttonIndex] = Joystick::GetStickForPort(index+1)->GetRawButton(buttonIndex+1);
		}
	}
	
	for(index = 0; index < sizeof(robotDiagnostics->gamepads)/sizeof(*robotDiagnostics->gamepads); index++) {
		robotDiagnostics->gamepads[index].x = Joystick::GetStickForPort(index+1)->GetAxis(Joystick::kXAxis);
		robotDiagnostics->gamepads[index].y = Joystick::GetStickForPort(index+1)->GetAxis(Joystick::kXAxis);
		robotDiagnostics->gamepads[index].z = Joystick::GetStickForPort(index+1)->GetAxis(Joystick::kXAxis);

		for(buttonIndex = 0; buttonIndex < 8; buttonIndex++) {
			robotDiagnostics->gamepads[index].buttons[buttonIndex] = Joystick::GetStickForPort(index+1)->GetRawButton(buttonIndex+1);
		}
	}

}

void RobotTelemetry::scheduledSend() {

        while (isEnabled) {
        	semTake(mRobotTelemetry,WAIT_FOREVER);
        	//update the data
        	updateTelemetryData();
        	//send the data
        	bhs_PCDataServer::getInstance().xmitRawData(getId(),getLength(),getEncoded());
        	semGive(mRobotTelemetry);
        	Wait(sendRate);
        }
}

int RobotTelemetry::start(RobotTelemetry* a_this) {
	a_this->scheduledSend();
	return 0;
}


/**
 * Implementation of custom printf handler...
 */
RobotDebug::RobotDebug() {
	isEnabled = false;
	mPrintData = semBCreate(SEM_Q_FIFO,SEM_FULL);
	mEnablePrint = semBCreate(SEM_Q_FIFO,SEM_FULL);
}

RobotDebug::~RobotDebug() {
	
}

void RobotDebug::setEnabled(bool enable) {
	semTake(mEnablePrint,WAIT_FOREVER);
	isEnabled = enable;
	semGive(mEnablePrint);
}

void RobotDebug::print(const char* format, ...) {
	if(isEnabled) {
		semTake(mPrintData,WAIT_FOREVER);
		char dest[1024];
		va_list argptr;
		va_start(argptr, format);
		vsprintf(dest, format, argptr);
		va_end(argptr);
		bhs_PCDataServer::getInstance().xmitRawData(id,sizeof(dest),dest);
		semGive(mPrintData);
	}
}
