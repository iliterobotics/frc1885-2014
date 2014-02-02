#ifndef BHS_DRIVER_INPUT_H_
#define BHS_DRIVER_INPUT_H_

#include "Joystick.h"

#include "bhs_Constants.h"
#include "bhs_GlobalData.h"

using namespace std;

class bhs_DriverInput {
	public:
		// joysticks
		static const UINT32 JOYSTICK_DRIVER_1_PORT = 1;
		static const UINT32 JOYSTICK_DRIVER_2_PORT = 2;
		static const UINT32 JOYSTICK_OPERATOR_1_PORT = 3;
		
		// Drivetrain
		static const UINT32 BUTTON_USE_ARCADE_DRIVE = 3;

		// Intake (roller and tusks)
		static const UINT32 INTAKE_FORWARD = 5;
		static const UINT32 INTAKE_REVERSED = 7;
		static const UINT32 TUSKS_UP = 6;
		static const UINT32 TUSKS_DOWN = 8;
		
		//Shooter
        static const UINT32 HIGH_GOAL_FORWARD = 9;
        static const UINT32 HIGH_GOAL_REVERSE = 10;
        static const UINT32 LOW_GOAL_FORWARD = 9;
        static const UINT32 LOW_GOAL_REVERSE = 10;
		
		bhs_DriverInput(bhs_GlobalData*);
		virtual ~bhs_DriverInput();

		virtual void init();
		virtual void run();

	private:
		bhs_GlobalData* m_gd;

		Joystick m_joystick1;
		Joystick m_joystick2;
		Joystick m_controller;
};

#endif //BHS_DRIVER_INPUT_H_
