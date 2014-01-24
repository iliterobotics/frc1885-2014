#include "bhs_GDTUsks.h"

bhs_GDTusks::bhs_GDTusks() {
	mdt_tusksUp = false;
	mdt_tusksDown = false;
	mdt_leftTuskOutput = DoubleSolenoid::kOff;
	mdt_rightTuskOutput = DoubleSolenoid::kOff;
}

