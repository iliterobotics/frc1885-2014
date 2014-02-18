#include "bhs_Autonomous.h"

bhs_Autonomous::bhs_Autonomous(bhs_GlobalData* a_gd) 
: m_straightPID()
{	
	m_gd = a_gd;
	m_state = k_forward;
	m_distPID.setConstants(bhs_Constants::PID_DRIVE_P, bhs_Constants::PID_DRIVE_I, bhs_Constants::PID_DRIVE_D);
	m_straightPID.setConstants(bhs_Constants::PID_STRAIGHT_P, bhs_Constants::PID_STRAIGHT_I, bhs_Constants::PID_STRAIGHT_D);
	m_timer.Reset();
	m_secondBall = false;
}

bhs_Autonomous::~bhs_Autonomous() {
	m_gd = 0;
}

void bhs_Autonomous::init() {
	m_state = k_forward;
	resetDT();
}

void bhs_Autonomous::run() {
#if TWO_BALL_1
	twoBall1();
#else
	twoBall2();
#endif
}

void bhs_Autonomous::resetDT() {
	m_gd->mdd_joystick1X = 0;
	m_gd->mdd_joystick1Y = 0;
	m_gd->mdd_joystick2X = 0;
	m_gd->mdd_joystick2Y = 0;	

	m_distPID.reset();
	m_straightPID.reset();
}

int bhs_Autonomous::inchesToEncoder(float a_inches) {
	float circum = atan(1)*4 * bhs_Constants::WHEEL_DIAMETER;
	float rotations = a_inches / circum;
	float ticks = rotations * bhs_Constants::ENCODER_TICKS_PER_ROTATION;

	return (int)ticks;
}

float bhs_Autonomous::encoderToInches(int a_encoders) {
	return a_encoders / inchesToEncoder(1);
}

#if TWO_BALL_1
void bhs_Autonomous::twoBall1() {
	int target;
	printf("current state: %d\t\t timer: %f\twait1: %f\twait2: %f\n",
			m_state, m_timer.Get(), k_winchWaitTime1, k_winchWaitTime2);

	switch(m_state) {
	case k_forward:
		if(m_secondBall) {
			target = k_forwardDist2;
		} else {
			target = k_forwardDist1;
		}

		float distCurrent = encoderToInches(m_gd->mdd_leftEncoderCounts);
		float distOutput = m_distPID.getPID(distCurrent, target);
		float straightCurrent = m_gd->mdd_gyroAngle;
		float straightOutput = m_straightPID.getPID(straightCurrent, 0);

		m_gd->mdd_joystick1X = 0;
		m_gd->mdd_joystick1Y = -straightOutput - distOutput;
		m_gd->mdd_joystick2X = 0;
		m_gd->mdd_joystick2Y = straightOutput - distOutput;

		if(fabs(distCurrent-target) <= k_pidThreshold) {
			resetDT();
			m_state = k_shoot; //FIXME: This skips the waitHot
			m_timer.Reset();
			m_timer.Start();
		}
		break;

	case k_waitHot:
		resetDT();
		if(m_gd->mda_goalHot) {
			m_state = k_shoot;
		}
		break;

	case k_shoot:
		m_gd->mds_highGoalIn = false;
		m_gd->mds_highGoalOut = true;
		m_gd->mds_wench = false;
		if(m_secondBall) {
			m_state = k_finished;
		}
		if(m_timer.Get() >= k_winchWaitTime1) {
			m_state = k_rearm;
			m_secondBall = true;
			m_timer.Reset();
			m_timer.Start();
		}
		break;

	case k_rearm:
		m_gd->mds_highGoalOut = false;
		m_gd->mds_highGoalIn = true;
		m_gd->mds_wench = true;
		m_gd->mdt_tusksUp = true;
		m_gd->mdi_intakeForward = true;
		if(m_timer.Get() >= k_winchWaitTime2) {
			m_timer.Reset();
			m_state = k_backward;
		}
		break;

	case k_backward:
		target = k_backwardDist1 + k_forwardDist1;
		distCurrent = encoderToInches(m_gd->mdd_leftEncoderCounts);
		distOutput = m_distPID.getPID(distCurrent, target);
		straightCurrent = m_gd->mdd_gyroAngle;
		straightOutput = m_straightPID.getPID(straightCurrent, 0);

		m_gd->mdd_joystick1X = 0;
		m_gd->mdd_joystick1Y = -straightOutput - distOutput;
		m_gd->mdd_joystick2X = 0;
		m_gd->mdd_joystick2Y = straightOutput - distOutput;

		if(fabs(distCurrent-target) <= k_pidThreshold) {
			resetDT();
			m_state = k_intake;
		}
		break;

	case k_intake:
		m_gd->mdt_tusksUp = false;
		m_gd->mdt_tusksDown = true;
		m_secondBall = true;
		m_state = k_forward;
		break;

	case k_finished:
		resetDT();
		m_straightPID.reset();
		m_secondBall = false;
		break;

	default:
		resetDT();
	}
}

#else

void bhs_Autonomous::twoBall2() {
	int target;
	printf("current state: %d\t\t timer: %f\n",
			m_state, m_timer.Get());

	switch(m_state) {
	case k_startTimer:
		m_timer.Start();
		break;

	case k_intakeUp:
		m_gd->mdt_tusksUp = true;
		m_gd->mdi_intakeForward = true;
		if(m_timer.Get() <= k_intakeWait) {
			m_timer.Stop();
			m_timer.Reset();
			m_state = k_backward;
		}
		break;

	case k_backward:
		target = k_backwardDist;
		float distCurrent = encoderToInches(m_gd->mdd_leftEncoderCounts);
		float distOutput = m_distPID.getPID(distCurrent, target);
		float straightCurrent = m_gd->mdd_gyroAngle;
		float straightOutput = m_straightPID.getPID(straightCurrent, 0);

		m_gd->mdd_joystick1X = 0;
		m_gd->mdd_joystick1Y = -straightOutput - distOutput;
		m_gd->mdd_joystick2X = 0;
		m_gd->mdd_joystick2Y = straightOutput - distOutput;

		if(fabs(distCurrent-target) <= k_pidThreshold) {
			resetDT();
			m_state = k_forward;
		}
		break;

	case k_forward:
		target = k_forwardDist;
		distCurrent = encoderToInches(m_gd->mdd_leftEncoderCounts);
		distOutput = m_distPID.getPID(distCurrent, target);
		straightCurrent = m_gd->mdd_gyroAngle;
		straightOutput = m_straightPID.getPID(straightCurrent, 0);

		m_gd->mdd_joystick1X = 0;
		m_gd->mdd_joystick1Y = -straightOutput - distOutput;
		m_gd->mdd_joystick2X = 0;
		m_gd->mdd_joystick2Y = straightOutput - distOutput;

		if(fabs(distCurrent-target) <= k_pidThreshold) {
			resetDT();
			m_timer.Start();
			m_state = k_shoot1;
		}
		break;

	case k_shoot1:
		m_gd->mds_highGoalIn = false;
		m_gd->mds_highGoalOut = true;
		m_gd->mds_wench = false;
		if(m_timer.Get() <= k_shootWait) {
			m_timer.Stop();
			m_timer.Reset();
			m_state = k_winch;
		}
		break;

	case k_winch:
		m_gd->mds_highGoalOut = false;
		m_gd->mds_highGoalIn = true;
		m_gd->mds_wench = true;
		if(m_gd->mds_wenchLimit) {
			m_gd->mds_highGoalIn = false;
			m_gd->mds_wench = false;
			m_timer.Start();
			m_state = k_intakeDown;
		}
		break;

	case k_intakeDown:
		m_gd->mdi_intakeForward = false;
		m_gd->mdt_tusksUp = false;
		m_gd->mdt_tusksDown = true;
		if(m_timer.Get() <= k_intakeWait) {
			m_timer.Stop();
			m_timer.Reset();
			m_state = k_shoot2;
		}
		break;

	case k_shoot2:
		m_gd->mds_highGoalIn = false;
		m_gd->mds_highGoalOut = true;
		m_gd->mds_wench = false;
		m_state = k_finished;
		break;

	case k_finished:
		resetDT();
		m_straightPID.reset();
		break;

	default:
		resetDT();
	}
}

#endif

