#include "bhs_DriverInput.h"

bhs_DriverInput::bhs_DriverInput(bhs_GlobalData* a_gd) 
	: m_joystick1(JOYSTICK_DRIVER_1_PORT)
	, m_joystick2(JOYSTICK_DRIVER_2_PORT)
	, m_buttonboard(JOYSTICK_OPERATOR_1_PORT)
{
	m_gd = a_gd;
}

bhs_DriverInput::~bhs_DriverInput() {
	m_gd = 0;
}

void bhs_DriverInput::init() {
}

void bhs_DriverInput::run() {
	m_gd->mdd_joystick1X = m_joystick1.GetAxis(Joystick::kXAxis);
	m_gd->mdd_joystick1Y = -m_joystick1.GetAxis(Joystick::kYAxis);
	m_gd->mdd_joystick2X = m_joystick2.GetAxis(Joystick::kXAxis);
	m_gd->mdd_joystick2Y = -m_joystick2.GetAxis(Joystick::kYAxis);

	m_gd->mdd_buttonUseArcadeDrive = m_joystick1.GetRawButton(BUTTON_USE_ARCADE_DRIVE);
	
	printf("DriverInput:\n1x: %f\t1y: %f\t2x: %f\t2y: %f\tarcade: %d\n\n",
			m_gd->mdd_joystick1X,
			m_gd->mdd_joystick1Y,
			m_gd->mdd_joystick2X,
			m_gd->mdd_joystick2Y,
			m_gd->mdd_buttonUseArcadeDrive);
}
