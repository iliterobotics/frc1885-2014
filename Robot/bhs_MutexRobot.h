#ifndef BHS_MUTEX_ROBOT_H_
#define BHS_MUTEX_ROBOT_H_

#include "kernelLib.h"
#include "drv/timer/timerDev.h"

#include "RobotBase.h"

#include "bhs_Robot.h"

class bhs_MutexRobot : public RobotBase {
	public:
		bhs_MutexRobot();
		virtual ~bhs_MutexRobot();

		/*
		 * The default period for the periodic function calls (seconds)
		 * Setting the period to 0.0 will cause the periodic functions to follow
		 * the Driver Station packet rate of about 50Hz.
		 */
		static const double k_defaultPeriod = 0.0;

		virtual void StartCompetition();

		virtual void RobotInit();
		virtual void DisabledInit();
		virtual void AutonomousInit();
		virtual void TeleopInit();

		virtual void AutonomousPeriodic();
		virtual void TeleopPeriodic();

		void SetPeriod(double);
		double GetPeriod();
		double GetLoopsPerSec();

		static void timerTask(bhs_MutexRobot*);

	private:
		bhs_Robot m_robot;

		bool m_disabledInitialized;
		bool m_autonomousInitialized;
		bool m_teleopInitialized;
		double m_period;

		SEM_ID m_periodSem;
		SEM_ID m_startSem;

		void infiniteTimerTask();

};

START_ROBOT_CLASS(bhs_MutexRobot);

#endif //BHS_MUTEX_ROBOT_H_
