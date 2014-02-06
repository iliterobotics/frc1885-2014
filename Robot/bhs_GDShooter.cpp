#include "bhs_GDShooter.h"

bhs_GDShooter::bhs_GDShooter() {
	mds_wenchLimit = false;
	
	mds_wenchForward = false;
	mds_wenchReverse = false;
	mds_lowGoalForward = false;
	mds_lowGoalReverse = false;
	mds_highGoalRelease = false;
	
	mds_wenchOutput = Relay::kOff;
	mds_lowGoalOutput = DoubleSolenoid::kOff;
	mds_highGoalOutput = false;
}
