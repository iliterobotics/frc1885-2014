#include "bhs_Test.h"

// Constant instantiations go here

bhs_Test::bhs_Test(bhs_GlobalData* in_data)
	: joystick(JOYSTICK_DRIVER_1_PORT)
{
	data = in_data;

	// Instantiations go here
	state = init;
}

bhs_Test::~bhs_Test()
{
	data = 0;
}

void bhs_Test::init()
{
	// Set members to initial value
	
	reset();
}

void bhs_Test::run()
{
	// Add test-specific run code here
	switch (state)
	{
	case runTest:
		switch (inState)
		{
		case preset:
			/* Add test-specific input values here
			 * input1(joystick 1 Y val, joystick 2 Y val);
			 */
			break;
		case active:
			input2();
			break;
		}
		break;
	case reset:
		reset();
		break;
	}
	if (joystick.getRawButton(8))
	{
		state = reset;
	}
	else if (joystick.getRawButton(9))
	{
		if (inState == preset)
		{
			inState = active;
		}
		else
		{
			inState = preset;
		}
	}
}

void bhs_Test::reset()
{
	// Add test-specific reset code here
	data->mdd_joystick1X = 0;
	data->mdd_joystick1Y = 0;
	data->mdd_joystick2X = 0;
	data->mdd_joystick2Y = 0;
	
	state = runTest;
}

void bhs_Test::input1(float joy1y, float joy2y)
{
	data->mdd_joystick1X = 0;
	data->mdd_joystick1Y = joy1y;
	data->mdd_joystick2X = 0;
	data->mdd_joystick2Y = joy2y;	 
}

void bhs_Test::input2()
{
	data->mdd_joystick1X = joystick.getAxis(Joystick::kXAxis);
	data->mdd_joystick1Y = joystick.getAxis(Joystick::kYAxis);
}

void bhs_Test::debugStatements()
{
	/* Add relevant debug messages here
	 * printf(*...*);
	 */
}
