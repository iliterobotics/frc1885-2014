#include "bhs_Talon.h"

bhs_Talon::bhs_Talon(UINT32 p_channel, float p_maxVel) 
	: m_act(p_channel)
	, m_maxVel(p_maxVel)
{
}

bhs_Talon::~bhs_Talon() {
}

void bhs_Talon::move(float p_speed) {
	if(fabs(p_speed)>m_maxVel) {
		p_speed = m_maxVel * p_speed / fabs(p_speed);
	}
	m_act.SetSpeed(p_speed);
}
