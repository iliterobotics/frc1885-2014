#include "bhs_OutputManager.h"

<<<<<<< HEAD
bhs_OutputManager::bhs_OutputManager(bhs_GlobalData* a_gd) 
	: m_driveLeftB(K_DRIVE_RIGHT_B)
	, m_driveRightB(K_DRIVE_LEFT_B)
{
	m_gd = a_gd;

	// Actuator declarations go here
=======
bhs_OutputManager::bhs_OutputManager(bhs_GlobalData* a_gd)
#if COMPRESSOR
: m_compressor(bhs_Constants::PRESSURE_SWITCH, bhs_Constants::COMPRESSOR_RELAY)
#endif        // COMRPESSOR
#if DRIVETRAIN
: m_driveLeftB(bhs_Constants::DT_LEFT_B_PWM)
, m_driveRightB(bhs_Constants::DT_RIGHT_B_PWM)
, m_driveLeftF(bhs_Constants::DT_LEFT_F_PWM)
, m_driveRightF(bhs_Constants::DT_RIGHT_F_PWM)
#endif        // DRIVETRAIN
#if INTAKE
, m_intakeRoller(bhs_Constants::INTAKE_PWM)
#endif        // INTAKE
#if TUSKS
, m_leftTusk(bhs_Constants::LEFT_TUSK_FORWARD_SOLENOID, bhs_Constants::LEFT_TUSK_REVERSE_SOLENOID)
, m_rightTusk(bhs_Constants::RIGHT_TUSK_FORWARD_SOLENOID, bhs_Constants::RIGHT_TUSK_REVERSE_SOLENOID)
#endif        // TUSKS
#if SHOOTER
	, m_wench(bhs_Constants::SHOOTER_WENCH_RELAY, Relay::kBothDirections)
    , m_lowGoal(bhs_Constants::SHOOTER_LOW_GOAL_FORWARD_SOLENOID, bhs_Constants::SHOOTER_LOW_GOAL_REVERSE_SOLENOID)
    , m_highGoalRelease(bhs_Constants::SHOOTER_HIGH_GOAL_SOLENOID)
#endif 		// SHOOTER
{
	m_gd = a_gd;

#if COMPRESSOR
	m_compressor.Start();        
#endif
>>>>>>> origin/silut
}

bhs_OutputManager::~bhs_OutputManager() {
	delete m_gd;
}


void bhs_OutputManager::init() {
	m_driveLeftB.SetSpeed(0);
	m_driveRightB.SetSpeed(0);
<<<<<<< HEAD

	// Set all actuators to initial position
=======
#endif        // DRIVETRAIN
#if INTAKE
	m_intakeRoller.SetSpeed(0);
#endif        // INTAKE
#if TUSKS
	m_leftTusk.Set(DoubleSolenoid::kOff);
	m_rightTusk.Set(DoubleSolenoid::kOff);
#endif        // TUSKS
#if SHOOTER
	m_wench.Set(Relay::kOff);
	m_highGoalRelease.Set(false);
	m_lowGoal.Set(DoubleSolenoid::kOff);
#endif
>>>>>>> origin/silut
}

void bhs_OutputManager::run() {
	safety();
	runMotors();
	runPneumatics();

	printf("\n");
}


void bhs_OutputManager::safety() {
	// Make sure all output values are within bounds
}

void bhs_OutputManager::runMotors() {
<<<<<<< HEAD
	m_driveLeftB.SetSpeed(m_gd->mdd_driveLeftPower);
	m_driveRightB.SetSpeed(m_gd->mdd_driveRightPower);
}

void bhs_OutputManager::runPneumatics() {
	// Actuate all pneumatics
=======
#if DRIVETRAIN
	//printf("dtLeft: %f\tdtRight: %f\t", m_gd->mdd_driveLeftPower, m_gd->mdd_driveRightPower);
	m_driveLeftB.SetSpeed(m_gd->mdd_driveLeftPower);
	m_driveRightB.SetSpeed(m_gd->mdd_driveRightPower);
	m_driveLeftF.SetSpeed(m_gd->mdd_driveLeftPower);
	m_driveRightF.SetSpeed(m_gd->mdd_driveRightPower);
#endif        // DRIVETRAIN
#if INTAKE
	printf("intake: %f\t", m_gd->mdi_intakePower);
	m_intakeRoller.SetSpeed(m_gd->mdi_intakePower);
#endif        // INTAKE
#if SHOOTER
	m_wench.Set(m_gd->mds_wenchOutput);
#endif
}

void bhs_OutputManager::runPneumatics() {
#if COMPRESSOR
	if(!m_compressor.Enabled()) {
		m_compressor.Start();
	}
#endif
#if TUSKS
	printf("leftTusk: %f\trightTusk: %f\t", m_gd->mdt_leftTuskOutput, m_gd->mdt_rightTuskOutput);
	m_leftTusk.Set(m_gd->mdt_leftTuskOutput);
	m_rightTusk.Set(m_gd->mdt_rightTuskOutput);
#endif
#if SHOOTER
	m_lowGoal.Set(m_gd->mds_lowGoalOutput);
	m_highGoalRelease.Set(m_gd->mds_highGoalOutput);
#endif
>>>>>>> origin/silut
}
