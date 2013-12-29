#include "bhs_Autonomous.h"

bhs_Autonomous::bhs_Autonomous()
: m_state(k_initState)
, m_timer()
{
}

bhs_Autonomous::~bhs_Autonomous() {
}

void bhs_Autonomous::init() {
	m_state = k_initState;
}

void bhs_Autonomous::run() {
	switch (m_state) {
	case k_startShooter:

	break;
	}

}
