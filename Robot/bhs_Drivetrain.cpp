#include "bhs_DriveTrain.h"

bhs_DriveTrain::bhs_DriveTrain(bhs_GDDrivetrain* a_dd) 
: m_driveStraightPID()
{
	m_dd = a_dd;

	m_driveStraightPID.setConstants(bhs_Constants::PID_DRIVE_P, bhs_Constants::PID_DRIVE_I, bhs_Constants::PID_DRIVE_D);
}

bhs_DriveTrain::~bhs_DriveTrain() {
	delete m_dd;
}

void bhs_DriveTrain::run() {
	if(m_dd->mdd_buttonUseArcadeDrive) {
		m_dd->mdd_arcadeDrive = !m_dd->mdd_arcadeDrive;
	}

	if(m_dd->mdd_arcadeDrive) {
		arcadeDrive();
	} else {
		tankDrive();
	}
}

void bhs_DriveTrain::tankDrive() {
	m_dd->mdd_driveLeftPower = -deadzone(m_dd->mdd_joystick1Y);
	m_dd->mdd_driveRightPower = deadzone(m_dd->mdd_joystick2Y);

	if (m_dd->mdd_reversed) {
	    float temp = -1.0 * m_dd->mdd_driveRightPower;
	    m_dd->mdd_driveRightPower = (-1.0 * m_dd->mdd_driveLeftPower);
	    m_dd->mdd_driveLeftPower = temp;
	}
}

void bhs_DriveTrain::arcadeDrive() {
	float forwardBackSpeed = deadzone(m_dd->mdd_joystick2Y);
	float leftRightSpeed = deadzone(m_dd->mdd_joystick2X);
	m_dd->mdd_driveLeftPower = limit(forwardBackSpeed + leftRightSpeed);
	m_dd->mdd_driveRightPower = limit(forwardBackSpeed - leftRightSpeed);
	
#if TWO_ENCODERS
	if(m_dd->mdd_arcadeDrive && fabs(m_dd->mdd_joystick2X) < bhs_Constants::JOYSTICK_DEAD_ZONE) {
		driveStraight();
	} else {
		driveStraightReset();
		float forwardBackSpeed = deadzone(m_dd->mdd_joystick2Y);
		float leftRightSpeed = deadzone(m_dd->mdd_joystick2X);

		if (m_dd->mdd_reversed) {
		    forwardBackSpeed = -1.0 * forwardBackSpeed;
		    leftRightSpeed = -1.0 * leftRightSpeed;
		}

		m_dd->mdd_driveLeftPower = limit(forwardBackSpeed + leftRightSpeed);
		m_dd->mdd_driveRightPower = limit(forwardBackSpeed - leftRightSpeed);
	}
#endif
}

void bhs_DriveTrain::driveStraightReset() {
	m_driveStraightPID.reset();
	//TODO: RESET ENCODERS

}

void bhs_DriveTrain::driveStraight() {
	int target = 0;
	int currentError = m_dd->mdd_rightEncoderCounts - m_dd->mdd_leftEncoderCounts;
	float pidOutput = m_driveStraightPID.getPID(currentError, target);
	m_dd->mdd_driveLeftPower = pidOutput;
	m_dd->mdd_driveRightPower = -pidOutput;
}


float bhs_DriveTrain::limit(float a_motorSpeed) {
	if (a_motorSpeed > 1.0) 
		return 1.0;
	else if (a_motorSpeed < -1.0) 
		return -1.0;
	else
		return a_motorSpeed;
}

float bhs_DriveTrain::deadzone(float a_joystickValue) {
	if (fabs(a_joystickValue) < bhs_Constants::JOYSTICK_DEAD_ZONE)
		return 0.0;
	else if (a_joystickValue > 1.0)
		return 1.0;
	else if (a_joystickValue < -1.0)
		return -1.0;
	else
		if (a_joystickValue > 0.0)
			return (a_joystickValue - bhs_Constants::JOYSTICK_DEAD_ZONE) / (1.0 - bhs_Constants::JOYSTICK_DEAD_ZONE);
		else
			return (a_joystickValue + bhs_Constants::JOYSTICK_DEAD_ZONE) / (1.0 - bhs_Constants::JOYSTICK_DEAD_ZONE);
}
