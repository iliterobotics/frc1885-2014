#include "bhs_SensorInput.h"

// Constant instantiations go here

bhs_SensorInput::bhs_SensorInput(bhs_GlobalData* a_gd) 
	: m_leftEncoder(bhs_Constants::DIGITAL_INPUT_MODULE, bhs_Constants::LEFT_ENCODER_CHANNEL1, bhs_Constants::LEFT_ENCODER_CHANNEL2)
#if TWO_ENCODERS
	, m_rightEncoder(bhs_Contants::DIGITAL_INPUT_MODULE, bhs_Constants::RIGHT_ENCODER_CHANNEL1, bhs_Constants::RIGHT_ENCODER_CHANNEL2)
#endif	
	, m_gyro(bhs_Constants::ANALOG_INPUT_MODULE, bhs_Constants::GYRO_CHANNEL)
{
	m_gd = a_gd;

	m_leftEncoder.Start();
#if TWO_ENCODERS
	m_rightEncoder.Start();
#endif
	m_gyro.Reset();
}

bhs_SensorInput::~bhs_SensorInput() {
	m_gd = 0;
}

void bhs_SensorInput::init() {
	m_leftEncoder.Reset();
#if TWO_ENCODERS
	m_rightEncoder.Reset();
#endif
}

void bhs_SensorInput::run() {
	// Read values from sensors and store in global variables
	m_gd->mdd_leftEncoderCounts = m_leftEncoder.Get();
#if TWO_ENCODERS
	m_gd->mdd_rightEncoderCounts = m_rightEncoder.Get();
#endif
	m_gd->mdd_gyroAngle = m_gyro.GetAngle();
	printf("Gyro angle: %f\n", m_gd->mdd_gyroAngle);
}
