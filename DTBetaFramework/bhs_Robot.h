#ifndef BHS_ROBOT_H
#define BHS_ROBOT_H

#include "DriverStationLCD.h"
#include "Watchdog.h"

#include "bhs_Drivetrain.h"


class bhs_Robot {
public:
	bhs_Robot();
	~bhs_Robot();

	void disabledInit();
	void autonomousInit();
	void autonomous();
	void teleopInit();
	void teleop();

private:
	bhs_Drivetrain m_dt;
	
};

#endif // BHS_ROBOT_H
