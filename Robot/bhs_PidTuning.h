#include "Robot/bhs_PID.h"
#include "AnalogChannel.h"
#include "Talon.h"
#include "Joystick.h"
#include "bhs_GlobalData.h"

class bhs_PidTuning
{
	public:
		bhs_PidTuning(bhs_GlobalData*, bhs_PID*, Joystick*, bool);
		void apply();
	private:
		bhs_GlobalData* data;
		
		Joystick* input;
		bhs_PID* pid;
		
		bool debug;
		
		void handleInputs();
		void debugMessages();
};
