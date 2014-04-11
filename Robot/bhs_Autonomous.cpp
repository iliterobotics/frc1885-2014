#include "bhs_Autonomous.h"
#include "DataDiagnostic.h"

bhs_Autonomous::bhs_Autonomous(bhs_GlobalData* a_gd) 
: m_leftDistPID()
, m_rightDistPID()
, m_timer()
{	
	m_gd = a_gd;

	m_rightDistPID.setConstants(bhs_Constants::PID_DRIVE_P, bhs_Constants::PID_DRIVE_I, bhs_Constants::PID_DRIVE_D);
	m_leftDistPID.setConstants(bhs_Constants::PID_DRIVE_P, bhs_Constants::PID_DRIVE_I, bhs_Constants::PID_DRIVE_D);
	
	m_state = k_forward;
	m_ds = DriverStation::GetInstance();

	m_secondBall = false;
}

bhs_Autonomous::~bhs_Autonomous() {
	m_gd = 0;
}

void bhs_Autonomous::init() {
	m_state = k_forward;
	reset();
}

//CHANGED
void bhs_Autonomous::run() {
	if (m_ds->GetDigitalIn(1)) {
		hotGoalForward();
	}else {
		twoBall();
	}

}

void bhs_Autonomous::reset() {
	m_gd->mdd_joystick1X = 0;
	m_gd->mdd_joystick1Y = 0;
	m_gd->mdd_joystick2X = 0;
	m_gd->mdd_joystick2Y = 0;	

	m_rightDistPID.reset();
	m_leftDistPID.reset();
}

int bhs_Autonomous::inchesToEncoder(float a_inches) {
#if PRODUCTION_ROBOT
	float circum = atan(1)*4 * bhs_Constants::WHEEL_DIAMETER;
	float rotations = a_inches / circum;
	float ticks = rotations * bhs_Constants::ENCODER_TICKS_PER_ROTATION;

	return (int)ticks;
#else
	return (int)(a_inches * k_ticksPerInch);
#endif
}

float bhs_Autonomous::encoderToInches(int a_encoders) {
	return a_encoders / inchesToEncoder(1);
}

void bhs_Autonomous::hotGoalForward() {
	bool isHot = false;
	int target = -k_dist;

	switch(m_state) {
	printf("state: %d\n", m_state);
	case k_forward:
		float distCurrentLeft = encoderToInches(m_gd->mdd_leftEncoderCounts);
		float distCurrentRight = encoderToInches(m_gd->mdd_rightEncoderCounts);
		
		float leftMotorOutput = m_leftDistPID.getPID(distCurrentLeft, target);
		float rightMotorOutput = m_rightDistPID.getPID(distCurrentRight, target);


		if(fabs(distCurrentRight)<1) {
			rightMotorOutput = -0.25;
		}
		if(fabs(distCurrentLeft)<1) {
			leftMotorOutput = -0.25;
		}
		
//		printf("dC: %f \t\tdO: %f\t\tsC: %f\t\tsO: %f\n", distCurrentRight, distOutputRight, straightCurrentRight, straightOutputRight);

		m_gd->mdd_joystick1X = 0;
		m_gd->mdd_joystick1Y = leftMotorOutput;
		m_gd->mdd_joystick2X = 0;
		m_gd->mdd_joystick2Y = rightMotorOutput;

		if(fabs(distCurrentLeft-target) <= 5 && fabs(distCurrentRight-target) <= 5){//k_pidThreshold1) {
			reset();
//			printf("dC: %f \t\tdO: %f\t\tsC: %f\t\tsO: %f\n", distCurrentRight, distOutputRight, straightCurrentRight, straightOutputRight);
			//TODO: add hot goal
			m_state = k_waitHot;
			m_timer.Reset();
			m_timer.Start();
		}
		break;

	case k_waitHot:
		isHot =  RobotTelemetry::getInstance().isHotGoal();
		double time = m_timer.Get();
		reset();
		if(isHot || time>5) {
			m_state = k_shoot;
			m_timer.Reset();
			m_timer.Start();
		}
		break;

	case k_shoot:
		m_gd->mds_highGoalIn = false;
		m_gd->mds_highGoalOut = true;
		if(m_timer.Get() >= k_winchWaitTime1) {
			m_timer.Reset();
			m_timer.Start();
			m_state = k_rearm;
		}
		break;


	case k_rearm:
		m_gd->mds_highGoalIn = true;
		m_gd->mds_highGoalOut = false;
		m_gd->mds_wench = true;
		if(m_timer.Get() >= k_winchWaitTime2) {
			m_timer.Reset();
			m_state = k_finished;
		}
		break;

	case k_finished:
		reset();
		m_rightDistPID.reset();
		m_leftDistPID.reset();
		m_gd->mds_wench = false;
		break;

	default:
		reset();
	}
}
void bhs_Autonomous::twoBall() {
	int target;
	//	printf("current state: %d\t\t timer: %f\twait1: %f\twait2: %f\n",
	//			m_state, m_timer.Get(), k_winchWaitTime1, k_winchWaitTime2);

	switch(m_state) {
	case k_forward:
		if(m_secondBall) {
			target = k_forwardDist2;
		} else {
			target = k_forwardDist1;
		}

		float distCurrentLeft = encoderToInches(m_gd->mdd_leftEncoderCounts);
		float leftMotorOutput = m_leftDistPID.getPID(distCurrentLeft, target);
		
		float distCurrentRight = encoderToInches(m_gd->mdd_rightEncoderCounts);
		float rightMotorOutput = m_rightDistPID.getPID(distCurrentRight, target);
		


		//		if(fabs(distCurrent)<.5) {m
		//			distOutput = -0.25;
		//		}

		m_gd->mdd_joystick1X = 0;
		m_gd->mdd_joystick1Y = leftMotorOutput;
		m_gd->mdd_joystick2X = 0;
		m_gd->mdd_joystick2Y = rightMotorOutput;

		if(fabs(distCurrentLeft-target) <= k_pidThreshold2 && fabs(distCurrentRight-target) <= k_pidThreshold2) {
			reset();
			m_state = k_shoot; //FIXME: This skips the waitHot
			m_timer.Reset();
			m_timer.Start();
		}
		break;


	case k_shoot:
		m_gd->mds_highGoalIn = false;
		m_gd->mds_highGoalOut = true;
		m_gd->mds_wench = false;
		if(m_secondBall) {
			m_state = k_finished;
		}
		if(m_timer.Get() >= k_winchWaitTime1) {
			m_state = k_rearm;
			m_secondBall = true;
			m_timer.Reset();
			m_timer.Start();
		}
		break;

	case k_rearm:
		m_gd->mds_highGoalIn = true;
		m_gd->mds_highGoalOut = false;
		m_gd->mds_wench = true;
		m_gd->mdt_tusksUp = true;
		m_gd->mdi_intakeForward = true;
		if(m_timer.Get() >= k_winchWaitTime2) {
			m_timer.Reset();
			m_state = k_backward;
		}
		break;

	case k_backward:
		target = k_backwardDist1 + k_forwardDist1;
		
		distCurrentLeft = encoderToInches(m_gd->mdd_leftEncoderCounts);
		leftMotorOutput = m_leftDistPID.getPID(distCurrentLeft, target);
				
		distCurrentRight = encoderToInches(m_gd->mdd_rightEncoderCounts);
		rightMotorOutput = m_rightDistPID.getPID(distCurrentRight, target);
		
		

		m_gd->mdd_joystick1X = 0;
		m_gd->mdd_joystick1Y = leftMotorOutput;
		m_gd->mdd_joystick2X = 0;
		m_gd->mdd_joystick2Y = rightMotorOutput;

		if(fabs(distCurrentLeft-target) <= k_pidThreshold2 && fabs(distCurrentRight-target) <= k_pidThreshold2) {
			reset();
			m_state = k_intake;
		}
		break;

	case k_intake:
		m_gd->mdt_tusksUp = false;
		m_gd->mdt_tusksDown = true;
		m_secondBall = true;
		m_state = k_forward;
		break;

	case k_finished:
		reset();
		m_rightDistPID.reset();
		m_leftDistPID.reset();
		m_secondBall = false;
		break;

	default:
		reset();
	}
}

/**Old Code using Gyros
 * #include "bhs_Autonomous.h"
#include "DataDiagnostic.h"

bhs_Autonomous::bhs_Autonomous(bhs_GlobalData* a_gd) 
: m_distPID()
, m_straightPID()
, m_timer()
{	
	m_gd = a_gd;

	m_distPID.setConstants(bhs_Constants::PID_DRIVE_P, bhs_Constants::PID_DRIVE_I, bhs_Constants::PID_DRIVE_D);
	m_straightPID.setConstants(bhs_Constants::PID_STRAIGHT_P, bhs_Constants::PID_STRAIGHT_I, bhs_Constants::PID_STRAIGHT_D);

	m_state = k_forward;
	m_ds = DriverStation::GetInstance();

	m_secondBall = false;
}

bhs_Autonomous::~bhs_Autonomous() {
	m_gd = 0;
}

void bhs_Autonomous::init() {
	m_state = k_forward;
	reset();
}

//CHANGED
void bhs_Autonomous::run() {
	if (m_ds->GetDigitalIn(1)) {
		hotGoalForward();
	}else {
		twoBall();
	}

}

void bhs_Autonomous::reset() {
	m_gd->mdd_joystick1X = 0;
	m_gd->mdd_joystick1Y = 0;
	m_gd->mdd_joystick2X = 0;
	m_gd->mdd_joystick2Y = 0;	

	m_distPID.reset();
	m_straightPID.reset();
}

int bhs_Autonomous::inchesToEncoder(float a_inches) {
#if PRODUCTION_ROBOT
	float circum = atan(1)*4 * bhs_Constants::WHEEL_DIAMETER;
	float rotations = a_inches / circum;
	float ticks = rotations * bhs_Constants::ENCODER_TICKS_PER_ROTATION;

	return (int)ticks;
#else
	return (int)(a_inches * k_ticksPerInch);
#endif
}

float bhs_Autonomous::encoderToInches(int a_encoders) {
	return a_encoders / inchesToEncoder(1);
}

void bhs_Autonomous::hotGoalForward() {
	bool isHot = false;
	int target = -k_dist;

	switch(m_state) {
	printf("state: %d\n", m_state);
	case k_forward:
		float distCurrent = encoderToInches(m_gd->mdd_leftEncoderCounts);
		float distOutput = m_distPID.getPID(distCurrent, target);
#if 1
		float straightCurrent = m_gd->mdd_gyroAngle;
#else
		int straightCurrent = m_gd->mdd_leftEncoderCounts - m_gd->mdd_rightEncoderCounts;
#endif
		float straightOutput = m_straightPID.getPID(straightCurrent, 0);

		if(fabs(distCurrent)<1) {
			distOutput = -0.25;
		}
//		printf("dC: %f \t\tdO: %f\t\tsC: %f\t\tsO: %f\n", distCurrent, distOutput, straightCurrent, straightOutput);

		m_gd->mdd_joystick1X = 0;
		m_gd->mdd_joystick1Y = -straightOutput - distOutput;
		m_gd->mdd_joystick2X = 0;
		m_gd->mdd_joystick2Y = straightOutput - distOutput;

		if(fabs(distCurrent-target) <= 5){//k_pidThreshold1) {
			reset();
//			printf("dC: %f \t\tdO: %f\t\tsC: %f\t\tsO: %f\n", distCurrent, distOutput, straightCurrent, straightOutput);
			//TODO: add hot goal
			m_state = k_waitHot;
			m_timer.Reset();
			m_timer.Start();
		}
		break;

	case k_waitHot:
		isHot =  RobotTelemetry::getInstance().isHotGoal();
		double time = m_timer.Get();
		reset();
		if(isHot || time>5) {
			m_state = k_shoot;
			m_timer.Reset();
			m_timer.Start();
		}
		break;

	case k_shoot:
		m_gd->mds_highGoalIn = false;
		m_gd->mds_highGoalOut = true;
		if(m_timer.Get() >= k_winchWaitTime1) {
			m_timer.Reset();
			m_timer.Start();
			m_state = k_rearm;
		}
		break;


	case k_rearm:
		m_gd->mds_highGoalIn = true;
		m_gd->mds_highGoalOut = false;
		m_gd->mds_wench = true;
		if(m_timer.Get() >= k_winchWaitTime2) {
			m_timer.Reset();
			m_state = k_finished;
		}
		break;

	case k_finished:
		reset();
		m_straightPID.reset();
		m_gd->mds_wench = false;
		break;

	default:
		reset();
	}
}
void bhs_Autonomous::twoBall() {
	int target;
	//	printf("current state: %d\t\t timer: %f\twait1: %f\twait2: %f\n",
	//			m_state, m_timer.Get(), k_winchWaitTime1, k_winchWaitTime2);

	switch(m_state) {
	case k_forward:
		if(m_secondBall) {
			target = k_forwardDist2;
		} else {
			target = k_forwardDist1;
		}

		float distCurrent = encoderToInches(m_gd->mdd_leftEncoderCounts);
		float distOutput = m_distPID.getPID(distCurrent, target);
		float straightCurrent = m_gd->mdd_gyroAngle;
		float straightOutput = m_straightPID.getPID(straightCurrent, 0);

		//		if(fabs(distCurrent)<.5) {
		//			distOutput = -0.25;
		//		}

		m_gd->mdd_joystick1X = 0;
		m_gd->mdd_joystick1Y = -straightOutput - distOutput;
		m_gd->mdd_joystick2X = 0;
		m_gd->mdd_joystick2Y = straightOutput - distOutput;

		if(fabs(distCurrent-target) <= k_pidThreshold2) {
			reset();
			m_state = k_shoot; //FIXME: This skips the waitHot
			m_timer.Reset();
			m_timer.Start();
		}
		break;


	case k_shoot:
		m_gd->mds_highGoalIn = false;
		m_gd->mds_highGoalOut = true;
		m_gd->mds_wench = false;
		if(m_secondBall) {
			m_state = k_finished;
		}
		if(m_timer.Get() >= k_winchWaitTime1) {
			m_state = k_rearm;
			m_secondBall = true;
			m_timer.Reset();
			m_timer.Start();
		}
		break;

	case k_rearm:
		m_gd->mds_highGoalIn = true;
		m_gd->mds_highGoalOut = false;
		m_gd->mds_wench = true;
		m_gd->mdt_tusksUp = true;
		m_gd->mdi_intakeForward = true;
		if(m_timer.Get() >= k_winchWaitTime2) {
			m_timer.Reset();
			m_state = k_backward;
		}
		break;

	case k_backward:
		target = k_backwardDist1 + k_forwardDist1;
		distCurrent = encoderToInches(m_gd->mdd_leftEncoderCounts);
		distOutput = m_distPID.getPID(distCurrent, target);
		straightCurrent = m_gd->mdd_gyroAngle;
		straightOutput = m_straightPID.getPID(straightCurrent, 0);

		m_gd->mdd_joystick1X = 0;
		m_gd->mdd_joystick1Y = -straightOutput - distOutput;
		m_gd->mdd_joystick2X = 0;
		m_gd->mdd_joystick2Y = straightOutput - distOutput;

		if(fabs(distCurrent-target) <= k_pidThreshold2) {
			reset();
			m_state = k_intake;
		}
		break;

	case k_intake:
		m_gd->mdt_tusksUp = false;
		m_gd->mdt_tusksDown = true;
		m_secondBall = true;
		m_state = k_forward;
		break;

	case k_finished:
		reset();
		m_straightPID.reset();
		m_secondBall = false;
		break;

	default:
		reset();
	}
}*/

