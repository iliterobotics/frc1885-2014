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
		
		static const UINT32 BUTTON_USE_ARCADE_DRIVE = 3;
		
		
		bhs_DriverInput(bhs_GlobalData*);
		virtual ~bhs_DriverInput();

		virtual void init();
		virtual void run();

	private:
		bhs_GlobalData* m_gd;

		Joystick m_joystick1;
		Joystick m_joystick2;
		Joystick m_buttonboard;
};

#endif //BHS_DRIVER_INPUT_H_
