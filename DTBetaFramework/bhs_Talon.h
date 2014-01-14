#ifndef BHS_TALON_H
#define BHS_TALON_H

#include <Math.h>
#include "WPILib/Talon.h"

#include "bhs_Actuator.h"

class bhs_Talon : public bhs_Actuator {
public:
	bhs_Talon(UINT32 p_channel, float p_maxVel);
	~bhs_Talon();

	void move(float p_speed);
private:
	Talon m_act;
	float m_maxVel;

};

#endif	// BHS_TALON_H
