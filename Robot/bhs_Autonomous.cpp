#include "bhs_Autonomous.h"

// Constant instantiations go here

bhs_Autonomous::bhs_Autonomous(bhs_GlobalData* a_gd) 
	: m_straightPID()
{	
	m_gd = a_gd;

	m_straightPID.setConstants(bhs_Constants::PID_STRAIGHT_P, bhs_Constants::PID_STRAIGHT_I, bhs_Constants::PID_STRAIGHT_D);
	
	m_state = k_forward;
	m_encoderMarker = 0;
}

bhs_Autonomous::~bhs_Autonomous() {
	m_gd = 0;
}

void bhs_Autonomous::init() {
	// Set members to initial value
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
	return a_inches * 15.691;
#endif
}

float bhs_Autonomous::encoderToInches(int a_encoders) {
	return a_encoders / inchesToEncoder(1);
}

void bhs_Autonomous::moveForward15() {
	switch(m_state) {
		case k_forward:
			m_gd->mdd_joystick1X = 0;
			m_gd->mdd_joystick1Y = 0.8;
			m_gd->mdd_joystick2X = 0;
			m_gd->mdd_joystick2Y = 0.8;
			if(fabs(m_gd->mdd_encoderCounts) >= inchesToEncoder(15)) {
				reset();
				m_state = k_finished;
			}
		break;
		default:
			reset();
	}
}

void bhs_Autonomous::trapezoidal() {
	printf("%d:\t\t%f\t%d\n", m_state, m_gd->mdd_driveLeftPower, m_gd->mdd_encoderCounts);
	switch(m_state) {
		case k_forward:
			m_state = k_accel;
			m_gd->mdd_encoderCounts = 0;
		break;
		
		case k_accel:
			m_gd->mdd_joystick1Y += k_velDiff;
			m_gd->mdd_joystick2Y += k_velDiff;
			if(fabs(m_gd->mdd_joystick1Y) >= fabs(k_maxVel)
			|| fabs(m_gd->mdd_encoderCounts >= inchesToEncoder(k_dist))) {
				m_state = k_constVel;
				m_encoderMarker = m_gd->mdd_encoderCounts;
			}
			
		break;
		
		case k_constVel:
			m_gd->mdd_joystick1Y = k_maxVel;
			m_gd->mdd_joystick2Y = k_maxVel;
			if(fabs(m_gd->mdd_encoderCounts) >= (inchesToEncoder(k_dist)-m_encoderMarker)) {
				m_state = k_decel;
			}
			
		break;
		
		case k_decel:
			m_gd->mdd_joystick1Y -= k_velDiff;
			m_gd->mdd_joystick2Y -= k_velDiff;
			if(fabs(m_gd->mdd_driveLeftPower) <= 0
			|| fabs(m_gd->mdd_encoderCounts >= inchesToEncoder(k_dist)))
		break;
		
		default:
			reset();
	}
}

void bhs_Autonomous::pidAuto() {
	int target = 180;
	switch(m_state) {
		case k_forward:
			float current = encoderToInches(m_gd->mdd_encoderCounts);
			//int target = encoderToInches(1883);
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
