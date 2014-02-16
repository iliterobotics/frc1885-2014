#include "bhs_Autonomous.h"

bhs_Autonomous::bhs_Autonomous(bhs_GlobalData* a_gd) 
: m_straightPID()
{	
	m_gd = a_gd;
	m_state = k_forward;
	m_distPID.setConstants(bhs_Constants::PID_DRIVE_P, bhs_Constants::PID_DRIVE_I, bhs_Constants::PID_DRIVE_D);
	m_straightPID.setConstants(bhs_Constants::PID_STRAIGHT_P, bhs_Constants::PID_STRAIGHT_I, bhs_Constants::PID_STRAIGHT_D);
	m_timer.Reset();
}

bhs_Autonomous::~bhs_Autonomous() {
	m_gd = 0;
}

void bhs_Autonomous::init() {
	m_state = k_forward;
	reset();
}

void bhs_Autonomous::run() {
	hotGoalForward();
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
	float circum = atan(1)*4 * bhs_Constants::WHEEL_DIAMETER;
	float rotations = a_inches / circum;
	float ticks = rotations * bhs_Constants::ENCODER_TICKS_PER_ROTATION;

	return (int)ticks;
}

float bhs_Autonomous::encoderToInches(int a_encoders) {
	return a_encoders / inchesToEncoder(1);
}
void bhs_Autonomous::hotGoalForward() {
	int target;

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

		if(fabs(distCurrent)<1) {
			distOutput = -0.25;
		}
		printf("dC: %f \t\tdO: %f\t\tsC: %f\t\tsO: %f\n", distCurrent, distOutput, straightCurrent, straightOutput);

		m_gd->mdd_joystick1X = 0;
		m_gd->mdd_joystick1Y = -straightOutput - distOutput;
		m_gd->mdd_joystick2X = 0;
		m_gd->mdd_joystick2Y = straightOutput - distOutput;

		if(fabs(distCurrent-target) <= k_pidThreshold) {
			reset();
			m_state = k_shoot; //FIXME: This skips the waitHot
		}
		break;

	case k_waitHot:
		reset();
		if(m_gd->mda_goalHot) {
			m_state = k_shoot;
		}
		break;

	case k_shoot:
		m_gd->mds_highGoalOut = true;
		if(m_secondBall) {
			m_state = k_finished;
		} else {
			m_state = k_rearm;
		}
		break;
		
	case k_rearm:
		m_gd->mds_highGoalOut = false;
		m_gd->mds_wench = true;
		m_gd->mdt_tusksUp = true;
		m_gd->mdi_intakeForward = true;
		m_timer.Start();
		if(m_timer.Get() >= k_winchWaitTime) {
			m_timer.Reset();
			m_state = k_backward;
		}
		break;

	case k_backward:
		target = k_backwardDist1 - k_forwardDist1;

		distCurrent = encoderToInches(m_gd->mdd_leftEncoderCounts);
		distOutput = m_distPID.getPID(distCurrent, target);
		straightCurrent = m_gd->mdd_gyroAngle;
		straightOutput = m_straightPID.getPID(straightCurrent, 0);
		if(fabs(distCurrent)<1) {
			distOutput = -0.25;
		}
		printf("dC: %f \t\tdO: %f\t\tsC: %f\t\tsO: %f\n", distCurrent, distOutput, straightCurrent, straightOutput);
		
		m_gd->mdd_joystick1X = 0;
		m_gd->mdd_joystick1Y = -straightOutput - distOutput;
		m_gd->mdd_joystick2X = 0;
		m_gd->mdd_joystick2Y = straightOutput - distOutput;

		if(fabs(distCurrent-target) <= k_pidThreshold) {
			reset();
			m_state = k_intake;
		}
		break;

	case k_intake:
		m_gd->mdt_tusksDown = true;
		m_secondBall = true;
		m_state = k_forward;
		break;

	case k_finished:
		reset();
		m_straightPID.reset();
		break;

	default:
		reset();
	}
}
