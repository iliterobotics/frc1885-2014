#include "WPILib.h"

class DriveTrain : public SimpleRobot {
	Talon dt_left;
	Talon dt_right;
	Joystick joy_left;
	Joystick joy_right;
	
public:
	DriveTrain():
		dt_left(1),
		dt_right(2),
		joy_left(1),
		joy_right(2) {
	}
	
	void OperatorControl() {
		while(IsOperatorControl()) {
			dt_left.Set(joy_left.GetY());
			dt_right.Set(joy_right.GetY());
		}
	}
};
