#include "bhs_OutputManager.h"

bhs_OutputManager::bhs_OutputManager(bhs_GlobalData* a_gd)
#if COMPRESSOR
	: m_compressor(bhs_Constants::PRESSURE_SWITCH, bhs_Constants::COMPRESSOR_RELAY)
#endif	// COMRPESSOR
#if DRIVETRAIN
	: m_driveLeftB(bhs_Constants::DT_LEFT_B_PWM)
	, m_driveRightB(bhs_Constants::DT_RIGHT_B_PWM)
#endif	// DRIVETRAIN
#if INTAKE
	, m_intakeRoller(bhs_Constants::INTAKE_PWM)
#endif	// INTAKE
#if TUSKS
	, m_leftTusk(bhs_Constants::LEFT_TUSK_FORWARD_SOLENOID, bhs_Constants::LEFT_TUSK_REVERSE_SOLENOID)
	, m_rightTusk(bhs_Constants::RIGHT_TUSK_FORWARD_SOLENOID, bhs_Constants::RIGHT_TUSK_REVERSE_SOLENOID)
#endif	// TUSKS
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
#endif	// DRIVETRAIN
#if INTAKE
	m_intakeRoller.SetSpeed(0);
#endif	// INTAKE
#if TUSKS
	m_leftTusk.Set(DoubleSolenoid::kOff);
	m_rightTusk.Set(DoubleSolenoid::kOff);
#endif	// TUSKS
}

void bhs_OutputManager::run() {
	safety();
	runMotors();
	runPneumatics();
	
	printf("\n");
}


void bhs_OutputManager::safety() {
}

void bhs_OutputManager::runMotors() {
#if DRIVETRAIN
	printf("dtLeft: %f\tdtRight: %f\t", m_gd->mdd_driveLeftPower, m_gd->mdd_driveRightPower);
	m_driveLeftB.SetSpeed(m_gd->mdd_driveLeftPower);
	m_driveRightB.SetSpeed(m_gd->mdd_driveRightPower);
#endif	// DRIVETRAIN
#if INTAKE
	printf("intake: %f\t", m_gd->mdi_intakePower);
	m_intakeRoller.SetSpeed(m_gd->mdi_intakePower);
#endif	// INTAKE
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
}
