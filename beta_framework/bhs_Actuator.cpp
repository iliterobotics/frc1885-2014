#include "bhs_Actuator.h"

bhs_Actuator::bhs_Actuator(ActuatorType p_type, UINT32 p_channel) {
	if(p_type == k_talon) {
		m_talon = new Talon(p_channel);
		delete m_relay;
		delete m_solenoid;
		delete m_doubleSolenoid;
	} else if (p_type == k_solenoid) {
		m_solenoid = new Solenoid(p_channel);
		delete m_talon;
		delete m_relay;
		delete m_doubleSolenoid;
	}
}

bhs_Actuator::bhs_Actuator(ActuatorType p_type, UINT32 p_channel1, UINT32 p_channel2) {
	m_doubleSolenoid = new DoubleSolenoid(p_channel1, p_channel2);
	delete m_talon;
	delete m_relay;
	delete m_solenoid;
}

bhs_Actuator::bhs_Actuator(ActuatorType p_type, UINT32 p_channel, Relay::Direction p_direction) {
	m_relay = new Relay(p_channel, p_direction);
	delete m_talon; 
	delete m_solenoid;
	delete m_doubleSolenoid;
}

bhs_Actuator::~bhs_Actuator() {
	
}

void bhs_Actuator::move(float p_speed) {
	switch (m_type) {
		case k_talon:
			m_talon.SetSpeed(p_speed);
		break;

		case k_relay:
			if(p_speed == 0) {
				m_relay.Set(Relay::kOff);
			} else if(p_speed < 0) {
				m_relay.Set(Relay::kReverse);
			} else {
				m_relay.Set(Relay::kForward);
			}
		break;

		case k_solenoid:
			if(p_speed == 0) {
				m_solenoid.Set(m_solenoid.Get());
			} else if(p_speed < 0) {
				m_solenoid.Set(false);
			} else {
				m_solenoid.Set(true);
			}
		break;

		case k_doubleSolenoid:
			if(p_speed == 0) {
				m_doubleSolenoid.Set(m_doubleSolenoid.Get());
			} else if(p_speed < 0) {
				m_doubleSolenoid.Set(DoubleSolenoid::kReverse);
			} else {
				m_doubleSolenoid.Set(DoubleSolenoid::kForward);
			}
		break;

		default:
	}
}
