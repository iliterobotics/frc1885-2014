#include "bhs_MutexRobot.h"

bhs_MutexRobot::bhs_MutexRobot()
	: m_robot()
	, m_disabledInitialized(false)
	, m_autonomousInitialized(false)
	, m_teleopInitialized(false)
	, m_period(k_defaultPeriod)
{
	// configure for round-robin scheduling
	kernelTimeSlice(sysClkRateGet() / 100); // 1/100th of a second - what each task gets for time slice
	//taskDelay(sysClkRateGet() / 2);

	// create mutex for sync
	m_startSem = semBCreate(SEM_Q_FIFO, SEM_EMPTY);
	m_periodSem = semBCreate(SEM_Q_FIFO, SEM_EMPTY);

	// start timer tasks
	taskSpawn("BHS_Timer_Task", 0, 0, 20000, (FUNCPTR) bhs_MutexRobot::timerTask, (int) this, 0, 0, 0, 0, 0, 0, 0, 0, 0);
}

bhs_MutexRobot::~bhs_MutexRobot() {}

void bhs_MutexRobot::SetPeriod(double p_period) {
	m_period = p_period;
}

double bhs_MutexRobot::GetPeriod() {
	return m_period;
}

double bhs_MutexRobot::GetLoopsPerSec() {
	return 1.0 / m_period;
}

void bhs_MutexRobot::StartCompetition() {
	printf("start competition\n");

	// first and one-time initialization
	RobotInit();

	// loop forever, calling the appropriate mode-dependent function
	while (semTake(m_periodSem, WAIT_FOREVER) == OK) {
		// call the appropriate function depending upon the current robot mode
		if (IsDisabled()) {
			// call DisabledInit() if we are now just entering disabled mode from
			// either a different mode or from power-on
			if (!m_disabledInitialized) {
				DisabledInit();
				m_disabledInitialized = true;
				// reset the initialization flags for the other modes
				m_autonomousInitialized = false;
				m_teleopInitialized = false;
			}
		} else if (IsAutonomous()) {
			if (!m_autonomousInitialized) {
				AutonomousInit();
				m_autonomousInitialized = true;
				m_disabledInitialized = false;
				m_teleopInitialized = false;
			}
			AutonomousPeriodic();
		} else {
			if (!m_teleopInitialized) {
				TeleopInit();
				m_teleopInitialized = true;
				m_disabledInitialized = false;
				m_autonomousInitialized = false;
			}
			TeleopPeriodic();
		}
	}

	printf("end competition\n");
}

void bhs_MutexRobot::RobotInit() {
	semGive(m_startSem); // configure blocking mutex to allow other task to start
}

void bhs_MutexRobot::DisabledInit() {
	m_robot.disabledInit();
}

void bhs_MutexRobot::AutonomousInit() {
	m_robot.autonomousInit();
}

void bhs_MutexRobot::AutonomousPeriodic() {
	m_robot.autonomous();
}

void bhs_MutexRobot::TeleopInit() {
	m_robot.teleopInit();
}

void bhs_MutexRobot::TeleopPeriodic() {
	m_robot.teleop();
}

void bhs_MutexRobot::infiniteTimerTask() {
	int lnTicksToWaitBetweenRobotCycles = sysClkRateGet() / 25;

	semTake(m_startSem, WAIT_FOREVER);
	while (true) {
		semGive(m_periodSem);
		taskDelay(lnTicksToWaitBetweenRobotCycles);
	}
}

void bhs_MutexRobot::timerTask(bhs_MutexRobot* a_this) {
	a_this->infiniteTimerTask();
}
