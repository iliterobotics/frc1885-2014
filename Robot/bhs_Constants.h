#ifndef BHS_CONSTANTS_H_
#define BHS_CONSTANTS_H_

<<<<<<< HEAD
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
=======
#define PRODUCTION_ROBOT 1
#define TWO_ENCODERS 1

#define COMPRESSOR 0
#define DRIVETRAIN 1
#define INTAKE 1
#define TUSKS 0
#define SHOOTER 1

#define BHS_GYRO 0

class bhs_Constants {
public:
#if COMPRESSOR
	static const int PRESSURE_SWITCH = 5;
	static const int COMPRESSOR_RELAY = 1;
#endif

#if DRIVETRAIN
	static const double PID_STRAIGHT_P = 0.05; // default 0.0015
	static const double PID_STRAIGHT_I = 0.0000; // default 0.0
	static const double PID_STRAIGHT_D = 0.00000; // default -0.00
	static const double PID_DRIVE_P = 0.02; // default 0.0015
	static const double PID_DRIVE_I = 0.00003; // default 0.0
	static const double PID_DRIVE_D = 0.00000;
	static const float JOYSTICK_DEAD_ZONE = 0.1;
	static const int DIGITAL_INPUT_MODULE = 2;
	static const int LEFT_ENCODER_CHANNEL1 = 1;
	static const int LEFT_ENCODER_CHANNEL2 = 2;
	static const int ANALOG_INPUT_MODULE = 1;
	static const int GYRO_CHANNEL = 1;
	static const int DT_LEFT_B_PWM = 1;
	static const int DT_RIGHT_B_PWM = 3;
#if PRODUCTION_ROBOT
	static const float WHEEL_DIAMETER = 4.875;
	static const int ENCODER_TICKS_PER_ROTATION = 256;
	static const int RIGHT_ENCODER_CHANNEL1 = 3;
	static const int RIGHT_ENCODER_CHANNEL2 = 4;
	static const int DT_LEFT_F_PWM = 2;
	static const int DT_RIGHT_F_PWM = 4;
#else
	static const int WHEEL_DIAMETER = 4;
	static const int ENCODER_TICKS_PER_ROTATION = 128;
#endif	// PRODUCTION_ROBOT
#endif	// DRIVETRAIN


#if INTAKE
	static const int INTAKE_PWM = 5;
#endif // INTAKE


#if TUSKS
	static const int LEFT_TUSK_FORWARD_SOLENOID = 1;
	static const int LEFT_TUSK_REVERSE_SOLENOID = 2;
	static const int RIGHT_TUSK_FORWARD_SOLENOID = 3;
	static const int RIGHT_TUSK_REVERSE_SOLENOID = 4;
#endif	// TUSKS

#if SHOOTER
		static const int SHOOTER_WENCH_LIMIT_CHANNEL = 6;
        static const int SHOOTER_WENCH_RELAY = 2;
        static const int SHOOTER_LOW_GOAL_FORWARD_SOLENOID = 5;
        static const int SHOOTER_LOW_GOAL_REVERSE_SOLENOID = 6;
        static const int SHOOTER_HIGH_GOAL_SOLENOID = 7;
#endif // SHOOTER
>>>>>>> origin/silut
};

#endif // BHS_CONSTANTS_H_
