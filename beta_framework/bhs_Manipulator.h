#ifndef BHS_MANIPULATOR_H
#define BHS_MANIPULATOR_H

#include <vector>

#include "WPILib/Joystick.h"

#include "bhs_Actuator.h"
#include "bhs_Limit.h"
#include "bhs_Target.h"

class bhs_Manipulator {
public:
	bhs_Manipulator(vector<Actuator::ActuatorType>, UINT32, UINT32, Target::TargetType, UINT32);
	~bhs_Manipulator();

	virtual void init() = 0;

	virtual void getInputs(AutonomousInputs, VisionInputs) = 0;
	virtual void getInputs(vector<Joystick>, VisionInputs) = 0;
	virtual void process() = 0;
	virtual void output() = 0;

	bool atLower();
	bool atUpper();
	float getCurrentPosition();


private:
	vector<Joystick> m_joysticks;

	vector<Actuator::ActuatorType> m_actuators;
	bhs_Limit m_limit;
	bhs_Target m_target;

};

#endif // BHS_MANIPULATOR_H
