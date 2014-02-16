#include "bhs_GDDrivetrain.h"

bhs_GDDrivetrain::bhs_GDDrivetrain() {
	mdd_joystick1X = 0;
	mdd_joystick1Y = 0;
	mdd_joystick2X = 0;
	mdd_joystick2Y = 0;
	mdd_buttonUseArcadeDrive = false;
	mdd_arcadeDrive = false;

	mdd_gyroAngle = 0;
	mdd_leftEncoderCounts = 0;
	mdd_rightEncoderCounts = 0;

	mdd_driveLeftPower = 0.0;
	mdd_driveRightPower = 0.0;
	mdd_reversed = false;
}

