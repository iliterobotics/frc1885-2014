#include "bhs_Autonomous2.h"

bhs_Autonomous2::bhs_Autonomous2(bhs_GlobalData* a_ds) {
	m_ds = a_ds;
	m_state = k_wench;
}

bhs_Autonomous2::~bhs_Autonomous2() {
	m_ds = 0;
}

void bhs_Autonomous2::init() {
	m_state = k_wench;
	reset();
}

void bhs_Autonomous2::reset() {
	m_ds->mds_wench = false;
	m_ds->mds_lowGoalForward = false;
	m_ds->mds_highGoalRelease = false;
}

void bhs_Autonomous2::testShooter() {
	switch(m_state) {
	case k_wench:
		time.Start();
		m_ds->mds_wench = true;
		if(time.Get() > 2) {
			time.Stop();
			m_ds->mds_wench = false;
			m_state = k_lowGoalForward;
			time.Reset();
		}
		break;
	case k_lowGoalForward:
		time.Start();
		m_ds->mds_lowGoalForward = true;
		if(time.Get() > 2) {
			time.Stop();
			m_ds->mds_lowGoalForward = false;
			m_state = k_highGoalRelease;
			time.Reset();
		}
		break;
	case k_highGoalRelease:
		time.Start();
		m_ds->mds_highGoalRelease = true;
		if(time.Get() > 2) {
			time.Stop();
			m_ds->mds_highGoalRelease = false;
			m_state = k_finished;
			time.Reset();
		}
		break;
	case k_finished:
		reset();
		break;
	default:
		reset();
	}
}

void bhs_Autonomous2::run() {
	testShooter();
}
