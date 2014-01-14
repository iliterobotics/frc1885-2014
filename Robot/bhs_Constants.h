#ifndef BHS_CONSTANTS_H_
#define BHS_CONSTANTS_H_

#include "types/vxTypesOld.h"
#include "Joystick.h"

class bhs_Constants {
	public:
		// drive train constants
		static const float JOYSTICK_DEAD_ZONE = 0.1;
		/*
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
		*/
		static const int WHEEL_DIAMETER = 6;
		static const int ENCODER_TICKS_PER_DEGREE = 4;

		static const int ENCODER_CHANNEL1 = 1;
		static const int ENCODER_CHANNEL2 = 2;
};

#endif // BHS_CONSTANTS_H_
