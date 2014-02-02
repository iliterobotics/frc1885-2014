#include "bhs_Autonomous.h"

bhs_Autonomous::bhs_Autonomous(bhs_GlobalData* a_gd) 
: m_straightPID()
{	
	m_gd = a_gd;

	m_distPID.setConstants(bhs_Constants::PID_DRIVE_P, bhs_Constants::PID_DRIVE_I, bhs_Constants::PID_DRIVE_D);
	m_straightPID.setConstants(bhs_Constants::PID_STRAIGHT_P, bhs_Constants::PID_STRAIGHT_I, bhs_Constants::PID_STRAIGHT_D);

	m_state = k_forward;
}

bhs_Autonomous::~bhs_Autonomous() {
	m_gd = 0;
}

void bhs_Autonomous::init() {
	m_state = k_forward;
	reset();
}

void bhs_Autonomous::run() {
#if REAL_AUTO
	hotGoalForward();
#else
	moveStraight(k_dist);
#endif
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

void bhs_Autonomous::moveStraight(int p_dist) {
	int target = -p_dist;

	switch(m_state) {
	case k_forward:
		float distCurrent = encoderToInches(m_gd->mdd_leftEncoderCounts);
		float distOutput = m_distPID.getPID(distCurrent, target);
		float straightCurrent = m_gd->mdd_gyroAngle;
		float straightOutput = m_straightPID.getPID(straightCurrent, 0);

		if(fabs(distCurrent)<1) {
			distOutput = -0.25;
		}

		m_gd->mdd_joystick1X = 0;
		m_gd->mdd_joystick1Y = -straightOutput + distOutput;
		m_gd->mdd_joystick2X = 0;
		m_gd->mdd_joystick2Y = straightOutput + distOutput;



		if(abs(distCurrent-target) <= k_pidThreshold) {
			printf("dC: %f \t\tdO: %f\t\tsC: %f\t\tsO: %f\n", distCurrent, distOutput, straightCurrent, straightOutput);
			m_state = k_finished;
		}
		break;

	case k_finished:
		reset();
		if(fabs(m_gd->mdd_gyroAngle-180)<=0.5) {
			float straightCurrent = m_gd->mdd_gyroAngle;
			float straightOutput = m_straightPID.getPID(straightCurrent, 180);
			
			m_gd->mdd_joystick1X = 0;
			m_gd->mdd_joystick1Y = -straightOutput;
			m_gd->mdd_joystick2X = 0;
			m_gd->mdd_joystick2Y = straightOutput;
			
			printf("sC: %f\t\tsO: %f\n", straightCurrent, straightOutput);

		}
		break;
	default:
		reset();
	}
}

void bhs_Autonomous::hotGoalForward() {
	int target = k_forwardDist;

	switch(m_state) {
	case k_forward:
		float current = encoderToInches(m_gd->mdd_leftEncoderCounts);
		float pidOutput = m_straightPID.getPID(current, target);
		printf("%f\t\t%d\t\t%f\n", current, target, pidOutput);
		m_gd->mdd_joystick1X = 0;
		m_gd->mdd_joystick1Y = pidOutput;
		m_gd->mdd_joystick2X = 0;
		m_gd->mdd_joystick2Y = pidOutput;
		if(fabs(m_gd->mdd_leftEncoderCounts-target) == k_pidThreshold) {
			m_state = k_waitHot;
		}
		break;

	case k_waitHot:
		reset();
		if(m_gd->mda_goalHot) {
			m_state = k_shoot;
		}
		break;

	case k_shoot:
		m_gd->mds_highGoalForward = true;
		m_state = k_finished;
		break;

	case k_finished:
		reset();
		m_straightPID.reset();
		break;

	default:
		reset();
	}
}
