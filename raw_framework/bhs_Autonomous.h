#ifndef BHS_AUTONOMOUS_H
#define BHS_AUTONOMOUS_H

#include "DriverStation.h"
#include "DriverStationLCD.h"
#include "Timer.h"


class bhs_Autonomous {
public:
	bhs_Autonomous();
	~bhs_Autonomous();

	void init();
	void run();

private:
	typedef enum {
		k_initState = 0
	} State;

	State m_state;

	Timer m_timer;
};

#endif
