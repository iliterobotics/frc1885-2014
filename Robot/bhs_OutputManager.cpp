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
, m_tusks(bhs_Constants::TUSK_DOWN_SOLENOID, bhs_Constants::TUSK_UP_SOLENOID)
#endif        // TUSKS
#if SHOOTER
, m_wench(bhs_Constants::SHOOTER_WENCH_RELAY)
, m_lowGoal(bhs_Constants::SHOOTER_LOW_GOAL_SOLENOID)
, m_highGoalRelease(bhs_Constants::SHOOTER_HIGH_GOAL_IN_SOLENOID, bhs_Constants::SHOOTER_HIGH_GOAL_OUT_SOLENOID)
#endif 		// SHOOTER
//, m_s6(5)
//, m_s7(7)
//, m_s8(8)
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
	m_tusks.Set(DoubleSolenoid::kOff);
#endif        // TUSKS
#if SHOOTER
	m_wench.Set(0);
	m_lowGoal.Set(false);
	m_highGoalRelease.Set(DoubleSolenoid::kOff);
#endif
}

void bhs_OutputManager::run() {
	safety();
	runMotors();
	runPneumatics();
	
//	m_s6.Set(true);
//	m_s7.Set(true);
//	m_s8.Set(true);
}


void bhs_OutputManager::safety() {
}

void bhs_OutputManager::runMotors() {
#if DRIVETRAIN
	m_driveLeftB.SetSpeed(m_gd->mdd_driveLeftPower);
	m_driveRightB.SetSpeed(m_gd->mdd_driveRightPower);
	m_driveLeftF.SetSpeed(m_gd->mdd_driveLeftPower);
	m_driveRightF.SetSpeed(m_gd->mdd_driveRightPower);
#endif        // DRIVETRAIN
#if INTAKE
	m_intakeRoller.SetSpeed(m_gd->mdi_intakeOutput);
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
	m_tusks.Set(m_gd->mdt_tusksOutput);

#endif
#if SHOOTER
	m_lowGoal.Set(m_gd->mds_lowGoal);
	m_highGoalRelease.Set(m_gd->mds_highGoalOutput);
#endif
}
