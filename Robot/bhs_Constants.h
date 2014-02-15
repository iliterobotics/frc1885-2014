#ifndef BHS_CONSTANTS_H_
#define BHS_CONSTANTS_H_

#define PRODUCTION_ROBOT 1
#define TWO_ENCODERS 1

#define COMPRESSOR 1
#define DRIVETRAIN 1
#define INTAKE 1
#define TUSKS 1
#define SHOOTER 1

#define BHS_GYRO 0

class bhs_Constants {
public:
	static const int ARDUINO_CHANNEL = 3;
	
#if COMPRESSOR
	static const int PRESSURE_SWITCH = 9;
	static const int COMPRESSOR_RELAY = 1;
	static const int PRESSURE_LEVEL_CHANNEL = 2;
#endif

#if DRIVETRAIN
	static const double PID_STRAIGHT_P = 0.1; // default 0.0015
	static const double PID_STRAIGHT_I = 0.0001; // default 0.0
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
	static const float WHEEL_DIAMETER = 4.5;
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
	/*static const int LEFT_TUSK_FORWARD_SOLENOID = 1;
	static const int LEFT_TUSK_REVERSE_SOLENOID = 2;
	static const int RIGHT_TUSK_FORWARD_SOLENOID = 3;
	static const int RIGHT_TUSK_REVERSE_SOLENOID = 4;*/
	static const int TUSK_DOWN_SOLENOID = 1;
	static const int TUSK_UP_SOLENOID = 2;
#endif	// TUSKS

#if SHOOTER
		static const int SHOOTER_WENCH_LIMIT_CHANNEL = 10;
        static const int SHOOTER_WENCH_RELAY = 6;
        static const int SHOOTER_LOW_GOAL_SOLENOID = 6;
        static const int SHOOTER_HIGH_GOAL_IN_SOLENOID = 3;
        static const int SHOOTER_HIGH_GOAL_OUT_SOLENOID = 4;
#endif // SHOOTER
};

#endif // BHS_CONSTANTS_H_
