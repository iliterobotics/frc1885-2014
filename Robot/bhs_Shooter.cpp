#include "bhs_Shooter.h"

bhs_Shooter::bhs_Shooter(bhs_GDShooter* a_ds) {
	m_ds = a_ds;
}

bhs_Shooter::~bhs_Shooter() {
	delete m_ds;
}

void bhs_Shooter::run() {
	if(!m_ds->mds_wenchLimit && m_ds->mds_wench) {
			m_ds->mds_wenchOutput = 1.0;
	} else {
		m_ds->mds_wenchOutput = 0.0;
	}
	
	m_ds->mds_lowGoalOutput = m_ds->mds_lowGoalForward;
	
	m_ds->mds_highGoalOutput = m_ds->mds_highGoalRelease;
}
