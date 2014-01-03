#include 'bhs_Actuator.h'

/**
 * Constructor for Talons and Solenoids.
 * \param p_type type of Actuator
 * \param p_channel port to which the Actuator is located
 */
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

/**
 * Constructor for DoubleSolenoid.
 * \param p_type type of Actuator
 * \param p_channel1 first port to which the Actuator is located
 * \param p_channel2 second port to which the Actuator is located
 */
bhs_Actuator::bhs_Actuator(ActuatorType p_type, UINT32 p_channel1, UINT32 p_channel2) {
	m_doubleSolenoid = new DoubleSolenoid(p_channel1, p_channel2);
	delete m_talon;
	delete m_relay;
	delete m_solenoid;
}

/**
 * Constructor for Relays.
 * \param p_type type of Actuator
 * \param p_channel port to which the Actuator is located
 * \param p_direction the direction that the Relay object will control
 */
bhs_Actuator::bhs_Actuator(ActuatorType p_type, UINT32 p_channel, Relay::Direction p_direction) {
	m_relay = new Relay(p_channel, p_direction);
	delete m_talon; 
	delete m_solenoid;
	delete m_doubleSolenoid;
}

/*
 * Destructor.
 * Destructs the Actuator
 */
bhs_Actuator::~bhs_Actuator() {
	
}

/**
 * Depending of the type of actuator, moves it accordingly.
 * Actuates Talons at a sepcified speed
 * If the Actuator is not a Talon, moves forard if the parameter is postive, backwards if negative, or turned off if 0
 * \param p_speed speed at which the Actuator will move
 */
void bhs_Actuator::move(float p_speed) {
	switch (m_type) {
		case k_talon:
			m_talon.Set(float);
		break;

		case k_relay:
			if(p_speed == 0) {
				m_relay.Set(Relay::kOff);
			} else if(p_speed < 0) {
				m_relay.Set(Relay::kReversed);
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
			})
		break;

		case k_doubleSolenoid:
			if(p_speed == 0) {
				m_doubleSolenoid.Set(m_doubleSolenoid.Get());
			} else if(p_speed < 0) {
				m_doubleSolenoid.Set(DoubleSolenoid::kReversed);
			} else {
				m_doubleSolenoid.Set(DoubleSolenoid::kForward);
			}
		break;

		default:
	}
}
