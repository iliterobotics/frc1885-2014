#ifndef BHS_CONSTANTS_H_
#define BHS_CONSTANTS_H_

#define PRODUCTION_ROBOT 0

#define COMPRESSOR 0
#define DRIVETRAIN 1
#define INTAKE 0
#define TUSKS 0
#define KICKER 0
#define LAUNCHER 0

#define BHS_GYRO 0

class bhs_Constants {
public:
#if COMPRESSOR
	static const int PRESSURE_SWITCH = 5;
	static const int COMPRESSOR_RELAY = 1;
#endif

#if DRIVETRAIN
	static const double PID_STRAIGHT_P = 0.01; // default 0.0015
	static const double PID_STRAIGHT_I = 0.0000225; // default 0.0
	static const double PID_STRAIGHT_D = 0.00000; // default -0.00
	static const float JOYSTICK_DEAD_ZONE = 0.1;
	static const int ENCODER_CHANNEL1 = 1;
	static const int ENCODER_CHANNEL2 = 2;
	static const int GYRO_CHANNEL = 1;
	static const int DT_LEFT_B_PWM = 1;
	static const int DT_RIGHT_B_PWM = 2;
#if PRODUCTION_ROBOT
	static const int WHEEL_DIAMETER = 5;
	static const int ENCODER_TICKS_PER_ROTATION = 256;
	static const int DT_LEFT_F = 3;
	static const int DT_RIGHT_F = 4;
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


#if KICKER
	static const int KICKER_SOLENOID = 3;
#endif


#if LAUNCHER

#endif	// LAUNCHER
};

#endif // BHS_CONSTANTS_H_
