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

		float mdd_gyroAngle;
		float mdd_gyroBiasVoltage;
		int mdd_encoderCounts;

		bool mdd_startDriveAngle;
		bool mdd_stopDriveAngle;
		float mdd_desiredAngle;
		float mdd_driveAnglePIDAddition;
		double mdd_driveAngleTimer;

		float mdd_driveLeftPower;
		float mdd_driveRightPower;
		
		float m_minSpeedKinetic;
		float m_minSpeedStatic;
	
};

#endif //BHS_GD_DRIVETRAIN_H_

