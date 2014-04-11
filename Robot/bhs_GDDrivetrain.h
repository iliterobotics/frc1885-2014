#ifndef BHS_GD_DRIVETRAIN_H_
#define BHS_GD_DRIVETRAIN_H_

#include "bhs_Constants.h"

class bhs_GDDrivetrain {
	public:
		bhs_GDDrivetrain();

		float mdd_joystick1X;
		float mdd_joystick1Y;
		float mdd_joystick2X;
		float mdd_joystick2Y;
		bool mdd_buttonUseArcadeDrive;
		bool mdd_arcadeDrive;
		bool mdd_reversed;

		//mdd_gryoAngle;
		int mdd_leftEncoderCounts;
		int mdd_rightEncoderCounts;

		float mdd_driveLeftPower;
		float mdd_driveRightPower;
};

#endif //BHS_GD_DRIVETRAIN_H_

