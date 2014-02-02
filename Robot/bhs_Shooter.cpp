#include "bhs_Shooter.h"

bhs_Shooter::bhs_Shooter(bhs_GDShooter* a_ds) {
	m_ds = a_ds;
}

bhs_Shooter::~bhs_Shooter() {
	delete m_ds;
}

void bhs_Shooter::run() {
	if(m_ds->mds_mFoward) {
		m_ds->mds_motorOutput = Relay::kFoward;
	} else if(m_ds->mds_mBackward) {
		m_ds->mds_motorOutput = Relay::kBackward;
	} else {
		m_ds->mds_motorOutput = Relay::kOff;
	}
}