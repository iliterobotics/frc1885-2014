#include "bhs_SensorInput.h"

// Constant instantiations go here

bhs_SensorInput::bhs_SensorInput(bhs_GlobalData* a_gd) 
<<<<<<< HEAD
	: m_encoder(bhs_Constants::ENCODER_CHANNEL1, bhs_Constants::ENCODER_CHANNEL2)
{
	m_gd = a_gd;

	// Sensor instantiations go here
=======
	: m_leftEncoder(bhs_Constants::DIGITAL_INPUT_MODULE, 1, 2)//bhs_Constants::LEFT_ENCODER_CHANNEL1, bhs_Constants::LEFT_ENCODER_CHANNEL2)
#if TWO_ENCODERS
	, m_rightEncoder(bhs_Constants::DIGITAL_INPUT_MODULE, 3, 4)// bhs_Constants::RIGHT_ENCODER_CHANNEL1, bhs_Constants::RIGHT_ENCODER_CHANNEL2)
#endif	
	, m_gyro(bhs_Constants::ANALOG_INPUT_MODULE, bhs_Constants::GYRO_CHANNEL)
#if SHOOTER
	, m_wenchLimitSwitch(bhs_Constants::SHOOTER_WENCH_LIMIT_CHANNEL)
#endif
{
	m_gd = a_gd;

	m_leftEncoder.Start();
#if TWO_ENCODERS
	m_rightEncoder.Start();
#endif
	m_gyro.Reset();
>>>>>>> origin/silut
}

bhs_SensorInput::~bhs_SensorInput() {
	m_gd = 0;
}

void bhs_SensorInput::init() {
<<<<<<< HEAD
	// Set members to initial value
	// Reset sensors
	m_encoder.Reset();
=======
	m_leftEncoder.Reset();
#if TWO_ENCODERS
	m_rightEncoder.Reset();
#endif
	m_gyro.Reset();
>>>>>>> origin/silut
}

void bhs_SensorInput::run() {
	// Read values from sensors and store in global variables
<<<<<<< HEAD
	m_gd->mdd_encoderCounts = m_encoder.Get();
=======
	m_gd->mdd_leftEncoderCounts = m_leftEncoder.Get();
#if TWO_ENCODERS
	m_gd->mdd_rightEncoderCounts = m_rightEncoder.Get();
#endif
	m_gd->mdd_gyroAngle = m_gyro.GetAngle();
	//printf("left encoder: %d\t\tright encoder: %d\n", m_gd->mdd_leftEncoderCounts, m_gd->mdd_rightEncoderCounts);
	//printf("gyro angle: %f\n", m_gd->mdd_gyroAngle);
	m_gd->mds_wenchLimit = m_wenchLimitSwitch.Get();
>>>>>>> origin/silut
}
