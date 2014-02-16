#include "bhs_Intake.h"

bhs_Intake::bhs_Intake(bhs_GlobalData* a_di) {
	m_di = a_di;
}

void bhs_Intake::run() {
	if(m_di->mdi_intakeForward) {
		m_di->mdi_intakeOutput = m_di->mdi_maxForwardPower;
	} else if(m_di->mdi_intakeReversed) {
		m_di->mdi_intakeOutput = m_di->mdi_maxReversedPower;
	} else {
		m_di->mdi_intakeOutput = 0.0;
	}

	if(m_di->mdt_tusksUp) {
		m_di->mdt_tusksOutput = DoubleSolenoid::kReverse;
	} else if (m_di->mdt_tusksDown) {
		m_di->mdi_intakeOutput = 0;
		m_di->mdt_tusksOutput = DoubleSolenoid::kForward;
	} else {
		m_di->mdt_tusksOutput = DoubleSolenoid::kOff;
	}
	
	
	if(!m_di->mds_wenchLimit) {
		m_di->mdi_intakeOutput = 0;
		m_di->mdt_tusksOutput = DoubleSolenoid::kForward;
	}
}
