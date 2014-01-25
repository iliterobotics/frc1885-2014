#include "bhs_PidTuning.h"

const static int pUp = 0;
const static int pDown = 0;
const static int dUp = 0;
const static int dDown = 0;

bhs_GlobalData* data();

Joystick* bhs_PidTuning::input();
bhs_PID* bhs_PidTuning::pid();

bool bhs_PidTuning::debug;

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
		switch (input->getRawButons())
		{
		case pUp:
			pid->setVals(pid->getP() += 0.01, pid->getD());
			break;
		case pDown:
			pid->setVals(pid->getP() -= 0.01, pid->getD());
			break;
		case dUp:
			pid->setVals(pid->getP(), pid->getD() += 0.01);
			break;
		case dDown:
			pid->setVals(pid->getP(), pid->getD() -= 0.01);
			break;
		}
	}
}

void bhs_PidTuning::debugMessages()
{
	printf("|P-Value: %f|/t|D-Value: %f|/n", pid->getP(), pid->getD());
}
