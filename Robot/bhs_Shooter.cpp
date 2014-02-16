#include "bhs_Shooter.h"

bhs_Shooter::bhs_Shooter(bhs_GDShooter* a_ds) {
	m_ds = a_ds;
}

bhs_Shooter::~bhs_Shooter() {
	delete m_ds;
}

void bhs_Shooter::run() {
	if(m_ds->mds_highGoalIn) {
		m_ds->mds_highGoalOutput = DoubleSolenoid::kForward;
	} else if(m_ds->mds_highGoalOut){
		m_ds->mds_highGoalOutput = DoubleSolenoid::kReverse;
	} else {
		m_ds->mds_highGoalOutput = DoubleSolenoid::kOff;
	}
	
	if(!m_ds->mds_wenchLimit && m_ds->mds_wench) {
		m_ds->mds_highGoalOutput = DoubleSolenoid::kForward;
		m_ds->mds_wenchOutput = 1.0;
	} else {
		m_ds->mds_wenchOutput = 0.0;
	}

}
