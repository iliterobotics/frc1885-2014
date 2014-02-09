#include "bhs_DriveTrain.h"

bhs_DriveTrain::bhs_DriveTrain(bhs_GDDrivetrain* a_dd) 
: m_driveStraightPID()
{
	m_dd = a_dd;

	m_driveStraightPID.setConstants(bhs_Constants::PID_DRIVE_P, bhs_Constants::PID_DRIVE_I, bhs_Constants::PID_DRIVE_D);
	m_driveStraightTarget = 0;

	m_driveStraightState = k_notStraight;
}

bhs_DriveTrain::~bhs_DriveTrain() {
	delete m_dd;
}

void bhs_DriveTrain::run() {
	if(m_dd->mdd_buttonUseArcadeDrive) {
		m_dd->mdd_arcadeDrive = !m_dd->mdd_arcadeDrive;
		m_driveStraightState = k_notStraight;
	}

	if(m_dd->mdd_arcadeDrive) {
		arcadeDrive();
	} else {
		tankDrive();
	}
}

void bhs_DriveTrain::tankDrive() {
	if (m_dd->mdd_reversed) {
		m_dd->mdd_driveLeftPower = deadzone(m_dd->mdd_joystick2Y);
		m_dd->mdd_driveRightPower = -deadzone(m_dd->mdd_joystick1Y);
	} else {
		m_dd->mdd_driveLeftPower = -deadzone(m_dd->mdd_joystick1Y);
		m_dd->mdd_driveRightPower = deadzone(m_dd->mdd_joystick2Y);
	}
}

void bhs_DriveTrain::arcadeDrive() {
	float forwardBackSpeed = deadzone(m_dd->mdd_joystick2Y);
	float leftRightSpeed = deadzone(m_dd->mdd_joystick2X);
	m_dd->mdd_driveLeftPower = limit(forwardBackSpeed + leftRightSpeed);
	m_dd->mdd_driveRightPower = limit(forwardBackSpeed - leftRightSpeed);
	switch(m_driveStraightState) {
	case k_notStraight:
		if(m_dd->mdd_arcadeDrive && fabs(m_dd->mdd_joystick2X) < bhs_Constants::JOYSTICK_DEAD_ZONE && m_dd->mdd_joystick2Y >= 0)
			m_driveStraightState = k_initStraight;
		break;

	case k_initStraight:
		m_driveStraightTarget = m_dd->mdd_rightEncoderCounts - m_dd->mdd_leftEncoderCounts;
		m_driveStraightPID.reset();
		m_driveStraightState = k_straight;
		printf("target: %d\n", m_driveStraightTarget);
		break;

	case k_straight:
		int currentError = m_dd->mdd_rightEncoderCounts - m_dd->mdd_leftEncoderCounts;
		float pidOutput = m_driveStraightPID.getPID(currentError, m_driveStraightTarget);

		printf("leftEnc: %d\trightEnc: %d\terror: %d\tpidOutput: %f\n",
				(m_dd->mdd_rightEncoderCounts),
				(m_dd->mdd_leftEncoderCounts),
				m_driveStraightTarget-currentError,
				pidOutput);

		m_dd->mdd_driveLeftPower += pidOutput;
		m_dd->mdd_driveRightPower -= pidOutput;

		if(!m_dd->mdd_arcadeDrive || fabs(m_dd->mdd_joystick2X) > bhs_Constants::JOYSTICK_DEAD_ZONE || fabs(m_dd->mdd_joystick2Y) < bhs_Constants::JOYSTICK_DEAD_ZONE) {
			m_driveStraightState = k_notStraight;
		}
		break;
	}


	if (m_dd->mdd_reversed) {
		forwardBackSpeed = -1.0 * forwardBackSpeed;
		leftRightSpeed = -1.0 * leftRightSpeed;
	}
}

void bhs_DriveTrain::driveStraightReset() {
	m_driveStraightPID.reset();

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
