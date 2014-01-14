#ifndef BHS_MANIPULATOR_H
#define BHS_MANIPULATOR_H

#include "WPILib/Joystick.h"

class bhs_Manipulator {
public:
	bhs_Manipulator();
	virtual ~bhs_Manipulator() = 0;

	virtual void init() = 0;
	virtual void run() = 0;

private:

	
};

#endif // BHS_MANIPULATOR_H
