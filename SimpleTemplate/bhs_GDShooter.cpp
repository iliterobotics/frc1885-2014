#include "bhs_GDShooter.h"

bhs_GDShooter::bhs_GDShooter() {
	mds_wenchLimit = false;
	
	mds_highGoalIn = false;
	mds_highGoalOut = false;
	mds_lowGoal = false;
	mds_wench = false;
	
	mds_wenchOutput = 0;
	mds_highGoalOutput = DoubleSolenoid::kOff;
}
