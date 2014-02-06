#ifndef BHS_ACTUATOR_H
#define BHS_ACTUATOR_H

#include <vector>

#include "WPILib/Talon.h"
#include "WPILib/Relay.h"
#include "WPILib/Solenoid.h"
#include "WPILib/DoubleSolenoid.h"

/** 
 * Encapsulates all types of Actuators.
 * All Actuators are as follows:
 *	- Variable speed motors (Talons)
 *	- Constant speed motors (Relays)
 *	- Pneumatics (Solenoids and DoubleSolenoids)
 */

class bhs_Actuator {
public:

	/**
	 * Identifies the type of the Actuator.
	 * Possbile Actuators include Talons, Relays, Solenoids, or Double Solenoids
	 */
	static typedef enum {
		k_talon = 0,
		k_relay,
		k_solenoid,
		k_doubleSolenoid
	} ActuatorType;

	/**
	 * Constructor for Talons and Solenoids.
	 * \param p_type type of Actuator
	 * \param p_channel port at which the Actuator is located
	 */
	bhs_Actuator(ActuatorType p_type, UINT32 p_channel);

	/**
	 * Constructor for DoubleSolenoid.
	 * \param p_type type of Actuator
	 * \param p_channel1 first port at which the Actuator is located
	 * \param p_channel2 second port at which the Actuator is located
	 */
	bhs_Actuator(ActuatorType p_type, UINT32 p_channel1, UINT32 p_channel2);

	/**
	 * Constructor for Relays.
	 * \param p_type type of Actuator
	 * \param p_channel port at which the Actuator is located
	 * \param p_direction the direction that the Relay object will control
	 */
	bhs_Actuator(ActuatorType p_type, UINT32 p_channel, Relay::Direction p_direction);

	/*
	 * Destructor.
	 * Destructs the Actuator
	 */
	~bhs_Actuator();

	 /**
 	  * Depending of the type of actuator, moves it accordingly.
      * Actuates Talons at a sepcified speed
      * If the Actuator is not a Talon, moves forard if the parameter is postive, backwards if negative, or turned off/remain at current state if 0
      * \param p_speed speed at which the Actuator will move
      */
	void move(float p_speed);
	

private:
	/**
	 * Type of Actuator.
	 * Defined in the paramater of every Actuator
	 * Can be one of four values: Talon, Relay, Solenoid, or Double Solenoid
	 */
	ActuatorType m_type;

	///Defined if the Actuator is a Talon, deleted otherwise
	Talon m_talon;

	///Defined if the Actuator is a Relay, deleted otherwise
	Relay m_relay;

	///Defined if the Actuator is a Solenoid, deleted otherwise
	Solenoid m_solenoid;

	///Defined if the Actuator is a Double Solenoid, deleted otherwise
	DoubleSolenoid m_doubleSolenoid;
};

#endif // BHS_ACTUATOR_H
