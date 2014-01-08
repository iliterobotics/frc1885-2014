#include "bhs_Robot.h"

bhs_Robot::bhs_Robot()
{
	Watchdog w;
	w.Kill();
}

bhs_Robot::~bhs_Robot() {
}

void bhs_Robot::disabledInit() {
}

void bhs_Robot::autonomousInit() {
}

void bhs_Robot::autonomous() {
}

void bhs_Robot::teleopInit() {
}

void bhs_Robot::teleop() {
}
