#include "bhs_OutputManager.h"

bhs_OutputManager::bhs_OutputManager(bhs_GlobalData* a_gd)
#if COMPRESSOR
: m_compressor(bhs_Constants::PRESSURE_SWITCH, bhs_Constants::COMPRESSOR_RELAY)
#endif        // COMRPESSOR
#if DRIVETRAIN
, m_driveLeftB(bhs_Constants::DT_LEFT_B_PWM)
, m_driveRightB(bhs_Constants::DT_RIGHT_B_PWM)
, m_driveLeftF(bhs_Constants::DT_LEFT_F_PWM)
, m_driveRightF(bhs_Constants::DT_RIGHT_F_PWM)
#endif        // DRIVETRAIN
#if INTAKE
, m_intakeRoller(bhs_Constants::INTAKE_PWM)
#endif        // INTAKE
#if TUSKS
, m_tusks(bhs_Constants::TUSK)
#endif        // TUSKS
#if SHOOTER
, m_wench(bhs_Constants::SHOOTER_WENCH_RELAY)
, m_lowGoal(bhs_Constants::SHOOTER_LOW_GOAL_SOLENOID)
, m_highGoalRelease(bhs_Constants::SHOOTER_HIGH_GOAL_SOLENOID)
#endif 		// SHOOTER
{
	m_gd = a_gd;

#if COMPRESSOR
	m_compressor.Start();        
#endif
}

bhs_OutputManager::~bhs_OutputManager() {
	delete m_gd;
}


void bhs_OutputManager::init() {
#if DRIVETRAIN
	m_driveLeftB.SetSpeed(0);
	m_driveRightB.SetSpeed(0);
#endif        // DRIVETRAIN
#if INTAKE
	m_intakeRoller.SetSpeed(0);
#endif        // INTAKE
#if TUSKS
	/*m_leftTusk.Set(DoubleSolenoid::kOff);
	m_rightTusk.Set(DoubleSolenoid::kOff);*/
	m_tusks.Set(false);
#endif        // TUSKS
#if SHOOTER
	m_wench.Set(0);
	m_lowGoal.Set(false);
	m_highGoalRelease.Set(false);
#endif
}

void bhs_OutputManager::run() {
	safety();
	runMotors();
	runPneumatics();
}


void bhs_OutputManager::safety() {
}

void bhs_OutputManager::runMotors() {
#if DRIVETRAIN
	//printf("dtLeft: %f\tdtRight: %f\t", m_gd->mdd_driveLeftPower, m_gd->mdd_driveRightPower);
	m_driveLeftB.SetSpeed(m_gd->mdd_driveLeftPower);
	m_driveRightB.SetSpeed(m_gd->mdd_driveRightPower);
	m_driveLeftF.SetSpeed(m_gd->mdd_driveLeftPower);
	m_driveRightF.SetSpeed(m_gd->mdd_driveRightPower);
#endif        // DRIVETRAIN
#if INTAKE
	//printf("intake: %f\t", m_gd->mdi_intakePower);
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
	//printf("leftTusk: %f\trightTusk: %f\t", m_gd->mdt_leftTuskOutput, m_gd->mdt_rightTuskOutput);
	m_tusks.Set(m_gd->mdt_tusksOutput);

#endif
#if SHOOTER
	m_lowGoal.Set(m_gd->mds_lowGoalOutput);
	m_highGoalRelease.Set(m_gd->mds_highGoalOutput);
#endif
}
