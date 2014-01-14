#include "bhs_Robot.h"

bhs_Robot::bhs_Robot()
	: m_dt(1, 2)
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
	m_dt.init();
}

void bhs_Robot::teleop() {
	m_dt.run();
}
