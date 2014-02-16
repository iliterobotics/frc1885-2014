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
	int target = -k_dist;

	switch(m_state) {
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
				printf("dC: %f \t\tdO: %f\t\tsC: %f\t\tsO: %f\n", distCurrent, distOutput, straightCurrent, straightOutput);
							
				m_gd->mdd_joystick1X = 0;
				m_gd->mdd_joystick1Y = -straightOutput - distOutput;
				m_gd->mdd_joystick2X = 0;
				m_gd->mdd_joystick2Y = straightOutput - distOutput;

				if(fabs(distCurrent-target) <= k_pidThreshold) {
					reset();
					printf("dC: %f \t\tdO: %f\t\tsC: %f\t\tsO: %f\n", distCurrent, distOutput, straightCurrent, straightOutput);
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
