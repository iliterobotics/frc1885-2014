#ifndef BHS_ACTUATOR_H
#define BHS_ACTUATOR_H

/** 
 *	Encapsulates all types of actuators:
 *		- Variable speed motors (Talons)
 *		- Constant speed motors (Relays)
 *		- Pneumatics (Solenoids and DoubleSolenoids)
 */
class bhs_Actuator {
public:
	bhs_Actuator();
	virtual ~bhs_Actuator() = 0;

	//virtual void move(float p_speed) = 0;

private:
};

#endif // BHS_ACTUATOR_H
