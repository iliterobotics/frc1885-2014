#include "bhs_Shooter.h"

bhs_Shooter::bhs_Shooter(bhs_GDShooter* a_ds) {
	m_ds = a_ds;
}

bhs_Shooter::~bhs_Shooter() {
	delete m_ds;
}

void bhs_Shooter::run() {
	if(!m_ds->mds_wenchLimit) {
		m_ds->mds_wenchOutput = m_dds->wench;
	} 
	
	m_ds->mds_lowGoalOutput = m_dds->mds_lowGoal;
	
	m_ds->mds_highGoalOutput = m_ds->mds_highGoalRelease;
}
