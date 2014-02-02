#include "bhs_Shooter.h"

bhs_Shooter::bhs_Shooter(bhs_GDShooter* a_ds) {
	m_ds = a_ds;
}

bhs_Shooter::~bhs_Shooter() {
	delete m_ds;
}

void bhs_Shooter::run() {
	if(m_ds->mds_wenchForward && !m_ds->mds_wenchLimit) {
		m_ds->mds_wenchOutput = Relay::kForward;
	} else if(m_ds->mds_wenchReverse) {
		m_ds->mds_wenchOutput = Relay::kReverse;
	} else {
		m_ds->mds_wenchOutput = Relay::kOff;
	}
	
	if(m_ds->mds_lowGoalForward) {
		m_ds->mds_lowGoalOutput = DoubleSolenoid::kForward;
	} else if(m_ds->mds_lowGoalReverse) {
		m_ds->mds_lowGoalOutput = DoubleSolenoid::kReverse;
	} else {
		m_ds->mds_lowGoalOutput = DoubleSolenoid::kOff;
	}
	
	m_ds->mds_highGoalOutput = m_ds->mds_highGoalRelease;
}
