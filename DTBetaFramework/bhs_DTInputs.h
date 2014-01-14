#ifndef BHS_DTINPUTS_H
#define BHS_DTINPUTS_H

#include "WPILib/Joystick.h"

class bhs_DTInputs {
public:
	bhs_DTInputs();
	~bhs_DTInputs();

	float getY1();
	float getY2();
	
private:

	Joystick m_joyLeft, m_joyRight;
};

#endif // BHS_DTINPUTS_H
