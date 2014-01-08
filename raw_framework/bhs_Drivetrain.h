#ifndef BHS_DRIVETRAIN_H
#define BHS_DRIVETRAIN_H

#include "bhs_Manipulator"

class bhs_Drivetrain : public bhs_Manipulator {
public:
	bhs_Drivetrain(vector<Actuator::ActuatorType>, UINT32, UINT32, Target::TargetType, UINT32);
	~bhs_Drivetrain();

	void init();

	void getInputs(vector<Joystick>, VisionInputs);
	void process();
	void output();

private:
	void tankDrive();
	void arcadeDrive();
	void nudgeDrive();

	void driveStraight();

	void moveInches(float);
	void turnDegress(float);
};


#endif // BHS_DRIVETRAIN_H