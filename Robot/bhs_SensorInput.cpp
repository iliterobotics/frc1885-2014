#include "bhs_SensorInput.h"

// Constant instantiations go here

bhs_SensorInput::bhs_SensorInput(bhs_GlobalData* a_gd) 
	: m_encoder(bhs_Constants::ENCODER_CHANNEL1, bhs_Constants::ENCODER_CHANNEL2)
	, m_gyro(bhs_Constants::GYRO_CHANNEL)
{
	m_gd = a_gd;

	m_encoder.Start();
	m_gyro.Reset();
}

bhs_SensorInput::~bhs_SensorInput() {
	m_gd = 0;
}

void bhs_SensorInput::init() {
	m_encoder.Reset();
}

void bhs_SensorInput::run() {
	// Read values from sensors and store in global variables
	m_gd->mdd_encoderCounts = m_encoder.Get();
	m_gd->mdd_gyroAngle = m_gyro.GetAngle();
	//printf("Gyro angle: %f\n", m_gd->mdd_gyroAngle);
}
