#include "bhs_OutputManager.h"

bhs_OutputManager::bhs_OutputManager(bhs_GlobalData* a_gd) 
	: m_compressor(bhs_Constants::PRESSURE_SWITCH, bhs_Constants::COMPRESSOR_RELAY)
	, m_driveLeftB(bhs_Constants::DT_LEFT_B_PWM)
	, m_driveRightB(bhs_Constants::DT_RIGHT_B_PWM)
	, m_intakeRoller(bhs_Constants::INTAKE_PWM)
	, m_leftTusk(bhs_Constants::LEFT_TUSK_FORWARD_SOLENOID, bhs_Constants::LEFT_TUSK_REVERSE_SOLENOID)
	, m_rightTusk(bhs_Constants::RIGHT_TUSK_FORWARD_SOLENOID, bhs_Constants::RIGHT_TUSK_REVERSE_SOLENOID)
{
	m_gd = a_gd;

	m_compressor.Start();	
}

bhs_OutputManager::~bhs_OutputManager() {
	delete m_gd;
}


void bhs_OutputManager::init() {
	m_driveLeftB.SetSpeed(0);
	m_driveRightB.SetSpeed(0);

	m_intakeRoller.SetSpeed(0);
	m_leftTusk.Set(DoubleSolenoid::kOff);
	m_rightTusk.Set(DoubleSolenoid::kOff);
}

void bhs_OutputManager::run() {
	safety();
	runMotors();
	runPneumatics();
}


void bhs_OutputManager::safety() {
}

void bhs_OutputManager::runMotors() {


	m_driveLeftB.SetSpeed(m_gd->mdd_driveLeftPower);
	m_driveRightB.SetSpeed(m_gd->mdd_driveRightPower);
}

void bhs_OutputManager::runPneumatics() {
	if(!m_compressor.Enabled()) {
		m_compressor.Start();
	}

	m_leftTusk.Set(m_gd->mdt_leftTuskOutput);
	m_rightTusk.Set(m_gd->mdt_rightTuskOutput);
}
