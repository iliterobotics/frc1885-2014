#include "bhs_Robot.h"

bhs_Robot::bhs_Robot() 
	: m_gd()
{
	Watchdog w;
	w.Kill();
	
	m_outputManager = new bhs_OutputManager(&m_gd);
	
	m_sensorInput = new bhs_SensorInput(&m_gd);
	m_autonomousInput = new bhs_Autonomous(&m_gd);
	m_driverInput = new bhs_DriverInput(&m_gd);

	m_drivetrain = new bhs_DriveTrain(&m_gd);
	m_intake = new bhs_Intake(&m_gd);
	m_shooter = new bhs_Shooter(&m_gd);
#if 1
	//robot telemetry diagnostics
	RobotTelemetry::getInstance().updateSendRate(0.5);
	RobotTelemetry::getInstance().enable();
	
	//enable debugging
	RobotDebug::getInstance().setEnabled(true);
#endif
}

bhs_Robot::~bhs_Robot() {
	delete m_sensorInput;
	delete m_autonomousInput;
	delete m_driverInput;
	
	delete m_drivetrain;
	delete m_intake;
	delete m_shooter;
}

void bhs_Robot::disabledInit() {
}

void bhs_Robot::autonomousInit() {
	m_sensorInput->init();
	m_autonomousInput->init();
}

void bhs_Robot::autonomous() {
	m_sensorInput->run();
	m_autonomousInput->run();
	normalRobotProcessing();
}

void bhs_Robot::teleopInit() {
	m_sensorInput->init();
	m_driverInput->init();
}

void bhs_Robot::teleop() {
	m_sensorInput->run();
	m_driverInput->run();
	normalRobotProcessing();
}

void bhs_Robot::normalRobotProcessing() {
	m_drivetrain->run();
	m_intake->run();
	m_shooter->run();
	
	m_outputManager->run();
}
