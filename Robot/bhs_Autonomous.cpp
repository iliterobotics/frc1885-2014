#include "bhs_Autonomous.h"

bhs_Autonomous::bhs_Autonomous(bhs_GlobalData* a_gd) 
	: m_straightPID()
{	
	m_gd = a_gd;

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
	pidAuto();
}

void bhs_Autonomous::reset() {
	m_gd->mdd_joystick1X = 0;
	m_gd->mdd_joystick1Y = 0;
	m_gd->mdd_joystick2X = 0;
	m_gd->mdd_joystick2Y = 0;	
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

void bhs_Autonomous::pidAuto() {
	int target = k_dist;
	switch(m_state) {
		case k_forward:
			float current = encoderToInches(m_gd->mdd_encoderCounts);
			float pidOutput = m_straightPID.getPID(current, target);
			float ivalue = m_straightPID.getI(1) * bhs_Constants::PID_STRAIGHT_I;
			
			printf("%f\t\t%d\t\t%f\t\t%f\n", current, target, pidOutput, ivalue);
			
			m_gd->mdd_joystick1X = 0;
			m_gd->mdd_joystick1Y = pidOutput;
			m_gd->mdd_joystick2X = 0;
			m_gd->mdd_joystick2Y = pidOutput;
			if(fabs(m_gd->mdd_encoderCounts-target) == k_pidThreshold) {
				reset();
				m_straightPID.reset();
				m_state = k_finished;
			}
		break;
		default:
			reset();
		}
}
