#include "bhs_Autonomous.h"

bhs_Autonomous::bhs_Autonomous(bhs_GlobalData* a_gd) {
	m_gd = a_gd;
	m_state = k_intakeForward;
}

bhs_Autonomous::~bhs_Autonomous() {
	m_gd = 0;
}

void bhs_Autonomous::init() {
	m_state = k_intakeForward;
	reset();
}

void bhs_Autonomous::reset() {
	m_gd->mdi_intakeForward = false;
	m_gd->mdi_intakeReversed = false;
	m_gd->mdt_tusksUp = false;
	m_gd->mdt_tusksDown = false;
}

void bhs_Autonomous::testIntake() {
	switch(m_state) {
	case k_intakeForward:
		time.Start();
		m_gd->mdi_intakeForward = true;
		if(time.Get() > 2) {
			time.Stop();
			m_gd->mdi_intakeForward = false;
			m_state = k_intakeReversed;
			time.Reset();
		}
		break;
	case k_intakeReversed:
		time.Start();
		m_gd->mdi_intakeReversed = true;
		if(time.Get() > 2) {
			time.Stop();
			m_gd->mdi_intakeReversed = false;
			m_state = k_tusksUp;
			time.Reset();
		}
		break;
	case k_tusksUp:
		time.Start();
		m_gd->mdt_tusksUp = true;
		if(time.Get() > 2) {
			time.Stop();
			m_gd->mdt_tusksUp = false;
			m_state = k_tusksDown;
			time.Reset();
		}
		break;
	case k_tusksDown:
		time.Start();
		m_gd->mdt_tusksDown = true;
		if(time.Get() > 2) {
			time.Stop();
			m_gd->mdt_tusksDown= false;
			m_state = k_finished;
			time.Reset();
		}
		break;
	case k_finished:
		reset();
	default:
		reset();
	}
}

void bhs_Autonomous::run() {
	testIntake();
}

