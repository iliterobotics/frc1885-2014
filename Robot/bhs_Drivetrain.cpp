#include "bhs_DriveTrain.h"

bhs_DriveTrain::bhs_DriveTrain(bhs_GDDrivetrain* a_dd) 
	: m_driveStraightPID()
{
	m_dd = a_dd;
	m_driveStraight = false;
	m_desiredAngle = 0.0;

	//m_driveStraightPID.init(bhs_Constants::PID_STRAIGHT_P, bhs_Constants::PID_STRAIGHT_I, bhs_Constants::PID_STRAIGHT_D);
}

bhs_DriveTrain::~bhs_DriveTrain() {
	delete m_dd;
}

void bhs_DriveTrain::run() {
	if (m_dd->mdd_arcadeDrive) {
		arcadeDrive();
	} else {
		tankDrive();
	}
	tankDrive();
}

void bhs_DriveTrain::arcadeDrive() {
	float l_forwardBackSpeed = deadzone(m_dd->mdd_joystick2Y);
	float l_leftRightSpeed;

	// the robot can only be in drive straight if the joysticks are in the proper orientation
	if (fabs(m_dd->mdd_joystick2X) < bhs_Constants::JOYSTICK_DEAD_ZONE &&
			fabs(m_dd->mdd_joystick2Y) > bhs_Constants::JOYSTICK_DEAD_ZONE) {
		// if we are not already in drive straight, set drive straight on and
		// then set the desired angle to the current gyro reading so that the
		// robot can lock on to this angle as it moves
		// if the robot is already in drive straight, then the desired angle
		// has already been set! only set it for the first iteration
		if (!m_driveStraight) {
			m_driveStraightPID.reset();
			m_desiredAngle = m_dd->mdd_gyroAngle;
			m_driveStraight = true;
		}
	} else {
		m_driveStraight = false;
	}

	if (m_driveStraight) {
		m_dd->mdd_driveAnglePIDAddition = -m_driveStraightPID.apply(m_dd->mdd_gyroAngle - m_desiredAngle);
		l_leftRightSpeed = m_dd->mdd_driveAnglePIDAddition;
	} 
	else {
		l_leftRightSpeed = deadzone(m_dd->mdd_joystick2X);
	}

	m_dd->mdd_driveLeftPower = limit(l_forwardBackSpeed + l_leftRightSpeed);
	m_dd->mdd_driveRightPower = limit(l_forwardBackSpeed - l_leftRightSpeed);
}

void bhs_DriveTrain::tankDrive() {
	m_dd->mdd_driveLeftPower = deadzone(m_dd->mdd_joystick1Y);
	m_dd->mdd_driveRightPower = -deadzone(m_dd->mdd_joystick2Y);
}

float bhs_DriveTrain::limit(float a_motorSpeed) {
	if (a_motorSpeed > 1.0) 
		return 1.0;
	else if (a_motorSpeed < -1.0) 
		return -1.0;
	else
		return a_motorSpeed;
}

float bhs_DriveTrain::deadzone(float a_joystickValue) {
	if (fabs(a_joystickValue) < bhs_Constants::JOYSTICK_DEAD_ZONE)
		return 0.0;
	else if (a_joystickValue > 1.0)
		return 1.0;
	else if (a_joystickValue < -1.0)
		return -1.0;
	else
		if (a_joystickValue > 0.0)
			return (a_joystickValue - bhs_Constants::JOYSTICK_DEAD_ZONE) / (1.0 - bhs_Constants::JOYSTICK_DEAD_ZONE);
		else
			return (a_joystickValue + bhs_Constants::JOYSTICK_DEAD_ZONE) / (1.0 - bhs_Constants::JOYSTICK_DEAD_ZONE);
}
