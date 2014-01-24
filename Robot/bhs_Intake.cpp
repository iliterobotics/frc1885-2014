#include "bhs_Intake.h"

bhs_Intake::bhs_Intake(bhs_GDIntake* a_di) {
	m_di = a_di;
}

void bhs_Intake::run() {
	if(m_di->mdi_intakeForward) {
		m_di->mdi_intakePower = m_di->mdi_maxForwardPower;
	} else if(m_di->mdi_intakeReversed) {
		m_di->mdi_intakePower = m_di->mdi_maxReversedPower;
	} else {
		m_di->mdi_intakePower = 0.0;
	}
}
