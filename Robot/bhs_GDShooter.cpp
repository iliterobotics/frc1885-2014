#include "bhs_GDShooter.h"

bhs_GDShooter::bhs_GDShooter() {
	mds_wenchLimit = false;
	
	mds_highGoalIn = false;
	mds_highGoalOut = false;
	mds_lowGoalIn = false;
	mds_lowGoalOut = false;
	mds_wench = false;
	
	mds_wenchOutput = 0;
	mds_lowGoalOutput = DoubleSolenoid::kOff;
	mds_highGoalOutput = DoubleSolenoid::kOff;
}
