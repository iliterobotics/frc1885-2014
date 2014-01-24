#include "bhs_GDDrivetrain.h"

bhs_GDDrivetrain::bhs_GDDrivetrain() {
	mdd_joystick1X = 0;
	mdd_joystick1Y = 0;
	mdd_joystick2X = 0;
	mdd_joystick2Y = 0;
	mdd_buttonUseArcadeDrive = false;
	mdd_arcadeDrive = false;

	mdd_gyroAngle = 0;
	mdd_gyroBiasVoltage = 0;
	mdd_encoderCounts = 0;

	mdd_startDriveAngle = false;
	mdd_stopDriveAngle = false;
	mdd_desiredAngle = 0.0;
	mdd_driveAnglePIDAddition = 0.0;
	mdd_driveAngleTimer = 0.0;

	mdd_driveLeftPower = 0.0;
	mdd_driveRightPower = 0.0;
	
	m_minSpeedKinetic = 0.05;
	m_minSpeedStatic = 0.05;
}

