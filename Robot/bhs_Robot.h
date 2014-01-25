#ifndef BHS_ROBOT_H_
#define BHS_ROBOT_H_

#include "DriverStationLCD.h"
#include "Watchdog.h"

#include "bhs_Constants.h"
#include "bhs_GlobalData.h"

#include "bhs_SensorInput.h"
#include "bhs_Autonomous.h"
#include "bhs_DriverInput.h"

#include "bhs_Drivetrain.h"

#include "bhs_OutputManager.h"

class bhs_Robot {
	public:
		bhs_Robot();
		~bhs_Robot();

		void disabledInit();
		void autonomousInit();
		void autonomous();
		void teleopInit();
		void teleop();

		void testInit();
		void test();
		
	private:
		void normalRobotProcessing();

		bhs_GlobalData m_gd;

		bhs_SensorInput* m_sensorInput;
		bhs_Autonomous* m_autonomousInput;
		bhs_DriverInput* m_driverInput;
		
		bhs_DriveTrain* m_drivetrain;

		bhs_OutputManager m_outputManager;
		
		bhs_Test* m_testInput;
};

#endif // BHS_ROBOT_H_
