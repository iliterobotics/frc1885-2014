#include "bhs_SensorInput.h"

// Constant instantiations go here

bhs_SensorInput::bhs_SensorInput(bhs_GlobalData* a_gd) 
{
	m_gd = a_gd;

	m_leftEncoder = new Encoder(bhs_Constants::LEFT_ENCODER_CHANNEL1, bhs_Constants::LEFT_ENCODER_CHANNEL2);
	m_rightEncoder = new Encoder(bhs_Constants::RIGHT_ENCODER_CHANNEL1, bhs_Constants::RIGHT_ENCODER_CHANNEL2, true);
	
	m_gyro = new Gyro(bhs_Constants::GYRO_CHANNEL);
	m_wenchLimitSwitch = new DigitalInput(bhs_Constants::SHOOTER_WENCH_LIMIT_CHANNEL);
	
	m_leftEncoder->Start();
#if TWO_ENCODERS
	m_rightEncoder->Start();
#endif
	m_gyro->Reset();
}

bhs_SensorInput::~bhs_SensorInput() {
	m_gd = 0;
	
	delete m_leftEncoder;
	delete m_rightEncoder;
	delete m_gyro;
	delete m_wenchLimitSwitch;
}

void bhs_SensorInput::init() {
	m_leftEncoder->Reset();
#if TWO_ENCODERS
	m_rightEncoder->Reset();
#endif
	m_gyro->Reset();
}

void bhs_SensorInput::run() {
	// Read values from sensors and store in global variables
	m_gd->mdd_leftEncoderCounts = m_leftEncoder->Get();
#if TWO_ENCODERS
	m_gd->mdd_rightEncoderCounts = m_rightEncoder->Get();
#endif
	m_gd->mdd_gyroAngle = m_gyro->GetAngle();
	printf("left encoder: %d\t\tright encoder: %d\n", m_gd->mdd_leftEncoderCounts, m_gd->mdd_rightEncoderCounts);
	//printf("gyro angle: %f\n", m_gd->mdd_gyroAngle);
	m_gd->mds_wenchLimit = m_wenchLimitSwitch->Get();
}
