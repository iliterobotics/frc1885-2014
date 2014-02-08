#include "bhs_Tusks.h"

bhs_Tusks::bhs_Tusks(bhs_GDTusks* a_dt) {
	m_dt = a_dt;
}

void bhs_Tusks::run() {
	if(m_dt->mdt_tusksUp) {
		m_dt->mdt_tusksOutput = false;
	} else if (m_dt->mdt_tusksDown) {
		m_dt->mdt_tusksOutput = true;
	}
}
