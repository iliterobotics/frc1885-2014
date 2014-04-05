#include "bhs_Shooter.h"

bhs_Shooter::bhs_Shooter(bhs_GlobalData* a_ds) {
	m_ds = a_ds;

	m_state = k_ready;
}

bhs_Shooter::~bhs_Shooter() {
	delete m_ds;
}

void bhs_Shooter::run() {
	if(!m_ds->mds_wenchLimit && (m_ds->mds_wench || m_ds->mds_engageWench)) {
		m_ds->mds_highGoalOutput = DoubleSolenoid::kForward;
		if(m_ds->mds_engageWench) {
			m_ds->mds_highGoalIn = true;
		}
		m_ds->mds_wenchOutput = 1.0;
	} else {
		m_ds->mds_wenchOutput = 0.0;
	}

	//Changed
	if(m_ds->mds_doubleShot){
		m_ds->mds_highGoalOut = true;
		m_ds->mds_lowGoal = true;
	}
	
	if(m_ds->mds_highGoalIn) {
		m_ds->mds_highGoalOutput = DoubleSolenoid::kForward;
	} else if(m_ds->mds_highGoalOut){
		m_ds->mds_highGoalOutput = DoubleSolenoid::kReverse;
	} else {
		m_ds->mds_highGoalOutput = DoubleSolenoid::kOff;
	}



/*
 * State machine to automatically wind down the winch as soon as high goal is fired.
 * May not want to implement because if limit switch fails, robot would die.
	switch(m_state) {
	case k_ready:
		if(m_ds->mds_highGoalOut) {
			m_state = k_shoot;
		}
		break;

	case k_shoot:
		m_ds->mds_highGoalOutput = DoubleSolenoid::kReverse;
		m_state = k_winch;
		break;

	case k_winch:
		m_ds->mds_highGoalOutput = DoubleSolenoid::kForward;
		m_ds->mds_wenchOutput = 1;
		if(m_ds->mds_wenchLimit) {
			m_ds->mds_wenchOutput = 0;
			m_state = k_ready;
		}
		break;
	}
*/

}
