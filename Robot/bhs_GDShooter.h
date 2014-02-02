#ifndef BHS_GD_SHOOTER_H_
#define BHS_GD_SHOOTER_H_

#include "Relay.h"
#include "DoubleSolenoid.h"

#include "bhs_Constants.h"

class bhs_GDShooter {
public:
	bhs_GDShooter();

	bool mds_wenchLimit;
	
	bool mds_wenchForward;
	bool mds_wenchReverse;
	bool mds_lowGoalForward;
	bool mds_lowGoalReverse;
	bool mds_highGoalRelease;
	
	Relay::Value mds_wenchOutput;
	DoubleSolenoid::Value mds_lowGoalOutput;
	bool mds_highGoalOutput;
};

#endif        // BHS_GD_SHOOTER_H_
