#include "bhs_DriverInput.h"

bhs_DriverInput::bhs_DriverInput(bhs_GlobalData* a_gd) 
	: m_joystick1(JOYSTICK_DRIVER_1_PORT)
	, m_joystick2(JOYSTICK_DRIVER_2_PORT)
	, m_controller(JOYSTICK_OPERATOR_1_PORT)
{
	m_gd = a_gd;
}

bhs_DriverInput::~bhs_DriverInput() {
	m_gd = 0;
}

void bhs_DriverInput::init() {
}

void bhs_DriverInput::run() {
	// Drivetrain
	m_gd->mdd_joystick1X = m_joystick1.GetAxis(Joystick::kXAxis);
	m_gd->mdd_joystick1Y = -m_joystick1.GetAxis(Joystick::kYAxis);
	m_gd->mdd_joystick2X = m_joystick2.GetAxis(Joystick::kXAxis);
	m_gd->mdd_joystick2Y = -m_joystick2.GetAxis(Joystick::kYAxis);

	m_gd->mdd_buttonUseArcadeDrive = m_joystick1.GetRawButton(BUTTON_USE_ARCADE_DRIVE);
	m_gd->mdd_reversed = m_joystick1.GetTrigger(GenericHID::kLeftHand);

	// Intake (roller and tusks)
	m_gd->mdi_intakeForward = m_controller.GetRawButton(INTAKE_FORWARD);
	m_gd->mdi_intakeReversed = m_controller.GetRawButton(INTAKE_REVERSED);

	m_gd->mdt_tusksUp = m_controller.GetRawButton(TUSKS_UP);
	m_gd->mdt_tusksDown = m_controller.GetRawButton(TUSKS_DOWN);

	// Shooter
	m_gd->mds_highGoalIn = m_controller.GetRawButton(HIGH_GOAL_IN);
	m_gd->mds_highGoalOut = m_controller.GetRawButton(HIGH_GOAL_OUT);

	m_gd->mds_lowGoal = m_controller.GetRawButton(LOW_GOAL);
	m_gd->mds_wench = m_controller.GetRawButton(WENCH);
	m_gd->mds_engageWench = m_controller.GetRawAxis(6)==1;
	m_gd->mds_doubleShot = m_controller.GetRawAxis(6)==-1;

}
