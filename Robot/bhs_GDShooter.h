#ifndef BHS_GD_SHOOTER_H_
#define BHS_GD_SHOOTER_H_

#include "Relay.h"
#include "DoubleSolenoid.h"

#include "bhs_Constants.h"

class bhs_GDShooter {
public:
	bhs_GDShooter();

	bool mds_wenchLimit;
	
	bool mds_highGoalRelease;
	bool mds_lowGoalForward;
	bool mds_wench;
	
	float mds_wenchOutput;
	bool mds_lowGoalOutput;
	bool mds_highGoalOutput;
};

#endif        // BHS_GD_SHOOTER_H_
