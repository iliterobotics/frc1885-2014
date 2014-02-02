#include "bhs_GDShooter.h"

bhs_GDShooter::bhs_GDShooter() {
	mds_highGoalForward = false;
	mds_highGoalReverse = false;
	mds_lowGoalForward = false;
	mds_lowGoalReverse = false;
	
	mds_highGoalOutput = Relay::kOff;
	mds_lowGoalOutput = DoubleSolenoid::kOff;
}
