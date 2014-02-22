#include "bhs_Autonomous.h"

bhs_Autonomous::bhs_Autonomous(bhs_GlobalData* a_gd) 
: m_straightPID()
{	
	m_gd = a_gd;
	//m_driverStation* = DriverStation.GetInstance();

	m_distPID.setConstants(bhs_Constants::PID_DRIVE_P, bhs_Constants::PID_DRIVE_I, bhs_Constants::PID_DRIVE_D);
	m_straightPID.setConstants(bhs_Constants::PID_STRAIGHT_P, bhs_Constants::PID_STRAIGHT_I, bhs_Constants::PID_STRAIGHT_D);

	m_oneBallState = k1_forward;
	m_twoBallState = k2_forward;
	
	m_secondBall = false;
}

bhs_Autonomous::~bhs_Autonomous() {
	m_gd = 0;
}

void bhs_Autonomous::init() {
	m_oneBallState = k1_forward;
	m_twoBallState = k2_forward;
	resetDT();
}

void bhs_Autonomous::run() {
	//if(m_driverStation.GetDigitalIn(k_dSButton)) {	//FIXME: If statement to determine one-ball/two-ball
	if(GetDigitalIn(k_dSButton)){	
		oneBall();
	} else {
		twoBall();
	}
}

void bhs_Autonomous::resetDT() {
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
void bhs_Autonomous::oneBall() {
	int target = -k_forwardDist1;

	switch(m_oneBallState) {
	case k1_forward:
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
		printf("dC: %f \t\tdO: %f\t\tsC: %f\t\tsO: %f\n", distCurrent, distOutput, straightCurrent, straightOutput);

		m_gd->mdd_joystick1X = 0;
		m_gd->mdd_joystick1Y = -straightOutput - distOutput;
		m_gd->mdd_joystick2X = 0;
		m_gd->mdd_joystick2Y = straightOutput - distOutput;

		if(fabs(distCurrent-target) <= k_pidThreshold) {
			resetDT();
			printf("dC: %f \t\tdO: %f\t\tsC: %f\t\tsO: %f\n", distCurrent, distOutput, straightCurrent, straightOutput);
			m_oneBallState = k1_shoot; //FIXME: This skips the waitHot
		}
		break;

	case k1_waitHot:
		resetDT();
		if(m_gd->mda_goalHot) {
			m_oneBallState = k1_shoot;
		}
		break;

	case k1_shoot:
		m_gd->mds_highGoalOut = true;
		m_oneBallState = k1_finished;
		break;

	case k1_finished:
		resetDT();
		m_straightPID.reset();
		break;

	default:
		resetDT();
	}
}
void bhs_Autonomous::twoBall() {
	int target;
	printf("current state: %d\t\t timer: %f\twait1: %f\twait2: %f\n",
			m_twoBallState, m_timer.Get(), k_winchWaitTime1, k_winchWaitTime2);

	switch(m_twoBallState) {
	case k2_forward:
		if(m_secondBall) {
			target = k_forwardDist2;
		} else {
			target = k_forwardDist1;
		}

		float distCurrent = encoderToInches(m_gd->mdd_leftEncoderCounts);
		float distOutput = m_distPID.getPID(distCurrent, target);
		float straightCurrent = m_gd->mdd_gyroAngle;
		float straightOutput = m_straightPID.getPID(straightCurrent, 0);

		m_gd->mdd_joystick1X = 0;
		m_gd->mdd_joystick1Y = -straightOutput - distOutput;
		m_gd->mdd_joystick2X = 0;
		m_gd->mdd_joystick2Y = straightOutput - distOutput;

		if(fabs(distCurrent-target) <= k_pidThreshold) {
			resetDT();
			m_twoBallState = k2_shoot;	//FIXME: This skips the waitHot
			m_timer.Reset();
			m_timer.Start();
		}
		break;

	case k2_waitHot:
		resetDT();
		if(m_gd->mda_goalHot) {
			m_twoBallState = k2_shoot;
		}
		break;

	case k2_shoot:
		m_gd->mds_highGoalIn = false;
		m_gd->mds_highGoalOut = true;
		m_gd->mds_wench = false;
		if(m_secondBall) {
			m_twoBallState = k2_finished;
		}
		if(m_timer.Get() >= k_winchWaitTime1) {
			m_twoBallState = k2_rearm;
			m_secondBall = true;
			m_timer.Reset();
			m_timer.Start();
		}
		break;

	case k2_rearm:
		m_gd->mds_highGoalOut = false;
		m_gd->mds_highGoalIn = true;
		m_gd->mds_wench = true;
		m_gd->mdt_tusksUp = true;
		m_gd->mdi_intakeForward = true;
		if(m_timer.Get() >= k_winchWaitTime2) {
			m_timer.Reset();
			m_twoBallState = k2_backward;
		}
		break;

	case k2_backward:
		target = k_backwardDist1 + k_forwardDist1;
		distCurrent = encoderToInches(m_gd->mdd_leftEncoderCounts);
		distOutput = m_distPID.getPID(distCurrent, target);
		straightCurrent = m_gd->mdd_gyroAngle;
		straightOutput = m_straightPID.getPID(straightCurrent, 0);

		m_gd->mdd_joystick1X = 0;
		m_gd->mdd_joystick1Y = -straightOutput - distOutput;
		m_gd->mdd_joystick2X = 0;
		m_gd->mdd_joystick2Y = straightOutput - distOutput;

		if(fabs(distCurrent-target) <= k_pidThreshold) {
			resetDT();
			m_twoBallState = k2_intake;
		}
		break;

	case k2_intake:
		m_gd->mdt_tusksUp = false;
		m_gd->mdt_tusksDown = true;
		m_secondBall = true;
		m_twoBallState = k2_forward;
		break;

	case k2_finished:
		resetDT();
		m_straightPID.reset();
		m_secondBall = false;
		break;

	default:
		resetDT();
	}
}
