#include "bhs_PidTuning.h"

const static int pUp = 0;
const static int pDown = 0;
const static int dUp = 0;
const static int dDown = 0;

bhs_GlobalData* data();

bhs_PidTuning::bhs_PidTuning(bhs_GlobalData* globals, bhs_PID* inPID, Joystick* inJoystick, bool debugOut)
{
	data = globals;
	pid = inPID;
	input = inJoystick;
	debug = debugOut;
}

void bhs_PidTuning::apply()
{
	handleInputs();
	if (debug)
	{
		debugMessages();
	}
}

void bhs_PidTuning::handleInputs()
{
	if (data->cycleTime % 200)
	{
		if (input->GetRawButton(6))
		{
			pid->setVals(pid->getP() + 0.01, pid->getD());
		}
		else if (input->GetRawButton(7))
		{
			pid->setVals(pid->getP() - 0.01, pid->getD());
		}
		if (input->GetRawButton(11))
		{
			pid->setVals(pid->getP(), pid->getD() + 0.01);
		}
		else if (input->GetRawButton(10))
		{
			pid->setVals(pid->getP(), pid->getD() - 0.01);
		}
	}
}

void bhs_PidTuning::debugMessages()
{
	printf("|P-Value: %f|/t|D-Value: %f|/n", pid->getP(), pid->getD());
}
