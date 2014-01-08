#ifndef BHS_CONSTANTS_H
#define BHS_CONSTANTS_H

class bhs_Constants {
public:
	// drive train constants
	static const float JOYSTICK_DEAD_ZONE;
	static const double PID_STRAIGHT_P;
	static const double PID_STRAIGHT_I;
	static const double PID_STRAIGHT_D;
	static const double PID_ANGLE_P;
	static const double PID_ANGLE_I;
	static const double PID_ANGLE_D;
	static const float DRIVE_ANGLE_THRESHOLD;
	static const float DRIVE_ANGLE_DIFF_THRESHOLD;
	static const float MIN_DRIVE_ANGLE_SPEED_STATIC;
	static const float MIN_DRIVE_ANGLE_SPEED_KINETIC;
};

#endif // BHS_CONSTANTS_H
