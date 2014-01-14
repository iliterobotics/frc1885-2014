#include "bhs_OutputManager.h"

bhs_OutputManager::bhs_OutputManager(bhs_GlobalData* a_gd) 
	: m_driveLeftB(K_DRIVE_RIGHT_B)
	, m_driveRightB(K_DRIVE_LEFT_B)
{
	m_gd = a_gd;

	// Actuator declarations go here
}

bhs_OutputManager::~bhs_OutputManager() {
	delete m_gd;
}


void bhs_OutputManager::init() {
	m_driveLeftB.SetSpeed(0);
	m_driveRightB.SetSpeed(0);

	// Set all actuators to initial position
}

void bhs_OutputManager::run() {
	safety();
	runMotors();
	runPneumatics();
}


void bhs_OutputManager::safety() {
	// Make sure all output values are within bounds
}

void bhs_OutputManager::runMotors() {
	m_driveLeftB.SetSpeed(m_gd->mdd_driveLeftPower);
	m_driveRightB.SetSpeed(m_gd->mdd_driveRightPower);
}

void bhs_OutputManager::runPneumatics() {
	// Actuate all pneumatics
}
