#ifndef BHS_TEST_H_
#define BHS_TEST_H_

#include <math.h>
#include <DriverStation.h>

#include "Timer.h"
#include "bhs_GlobalData.h"

#include "Joystick.h"

class bhs_Test
{
	public:
		// joysticks
		static const UINT32 JOYSTICK_DRIVER_1_PORT = 1;
	
		bhs_Test(bhs_GlobalData*);
		virtual ~bhs_Test();
		
		virtual void run();
		virtual void init();
	private:
		Joystick joystick;
		
		typedef enum
		{
			runTest = 0,
			reset
			// ...
		} State;
		typedef enum
		{
			preset = 0,
			active
			// ...
		} inputState;
		
		bhs_GlobalData* data;
		
		State state;
		inputState inState;
		
		Timer time;
		
		void reset();
		
		void input1(float, float);
		void input2();
		
		void debugStatements();
};

#endif BHS_TEST_H_
