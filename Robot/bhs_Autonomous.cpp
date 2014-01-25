#include "bhs_Autonomous.h"

// Constant instantiations go here

bhs_Autonomous::bhs_Autonomous(bhs_GlobalData* a_gd) {
	m_gd = a_gd;

	// Instantiations go here
	m_state = k_forward;
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
	moveForward15();
}

void bhs_Autonomous::reset() {
	m_gd->mdd_joystick1X = 0;
	m_gd->mdd_joystick1Y = 0;
	m_gd->mdd_joystick2X = 0;
	m_gd->mdd_joystick2Y = 0;
}

int bhs_Autonomous::inchesToEncoder(float a_inches) {
	float circum = atan(1)*4 * bhs_Constants::WHEEL_DIAMETER;
	float rotations = a_inches / circum;
	float ticks = rotations * 360 * 4;

	return (int)ticks;
}

void bhs_Autonomous::moveForward15() {
	switch(m_state) {
		case k_forward:
			m_gd->mdd_joystick1X = 0;
			m_gd->mdd_joystick1Y = 1.0;
			m_gd->mdd_joystick2X = 0;
			m_gd->mdd_joystick2Y = 1.0;
			if(m_gd->mdd_encoderCounts >= inchesToEncoder(15)) {
				m_state = k_finished;
			}
		break;
		default:
			reset();
	}
}
