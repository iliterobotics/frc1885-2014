#ifndef BHS_GD_SHOOTER_H_
#define BHS_GD_SHOOTER_H_

#include "Relay.h"
#include "DoubleSolenoid.h"

#include "bhs_Constants.h"

class bhs_GDShooter {
public:
	bhs_GDShooter();

	bool mds_highGoalForward;
	bool mds_highGoalReverse;
	bool mds_lowGoalForward;
	bool mds_lowGoalReverse;
	
	Relay::Value mds_highGoalOutput;
	DoubleSolenoid::Value mds_lowGoalOutput;
};

#endif        // BHS_GD_SHOOTER_H_
