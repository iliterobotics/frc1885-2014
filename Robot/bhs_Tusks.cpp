#include "bhs_Tusks.h"

bhs_Tusks::bhs_Tusks(bhs_GDTusks* a_dt) {
	m_dt = a_dt;
}

void bhs_Tusks::run() {
	if(m_dt->mdt_tusksUp) {
		m_dt->mdt_leftTuskOutput = DoubleSolenoid::kForward;
		m_dt->mdt_rightTuskOutput = DoubleSolenoid::kReverse;
	} else if(m_dt->mdt_tusksDown) {
		m_dt->mdt_leftTuskOutput = DoubleSolenoid::kReverse;
		m_dt->mdt_rightTuskOutput = DoubleSolenoid::kForward;
	} else {
		m_dt->mdt_leftTuskOutput = DoubleSolenoid::kOff;
		m_dt->mdt_rightTuskOutput = DoubleSolenoid::kOff;
	}
}
