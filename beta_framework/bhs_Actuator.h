#ifndef BHS_ACTUATOR_H
#define BHS_ACTUATOR_H

#include <vector>

#include "WPILib/Talon.h"
#include "WPILib/Relay.h"
#include "WPILib/Solenoid.h"
#include "WPILib/DoubleSolenoid.h"

/** 
	Encapsulates all types of actuators:
		- Variable speed motors (Talons)
		- Constant speed motors (Relays)
		- Pneumatics (Solenoids and DoubleSolenoids)
*/
class bhs_Actuator {
public:
	/*
		Identifies the type of the Actuator.
	*/
	static typedef enum {
		k_talon = 0,
		k_relay,
		k_solenoid,
		k_doubleSolenoid
	} ActuatorType;

	// Constructor for Talons and Soleniods
	bhs_Actuator(ActuatorType, UINT32);
	// Constructor for DoubleSolenoid
	bhs_Actuator(ActuatorType, UINT32, UINT32);
	// Constructor for Relays
	bhs_Actuator(ActuatorType, UINT32, Relay::Direction);

	~bhs_Actuator();

	/*
		Actuates Talons at specified speed
		If Actuator is not a Talon, move forward if parameter is positive, backward if negative.
	*/
	void move(float);
	void move(Relay::Value);
	void move(bool);
	void move(DoubleSolenoid::Value);
	
	void moveTo(float);
	void moveTo(int);

private:
	ActuatorType m_type;

	Talon m_talon;
	Relay m_relay;
	Solenoid m_solenoid;
	DoubleSolenoid m_doubleSolenoid;
};

#endif // BHS_ACTUATOR_H
