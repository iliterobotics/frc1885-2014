#ifndef BHS_AUTONOMOUS_H_
#define BHS_AUTONOMOUS_H_

#include <math.h>

#include "bhs_GlobalData.h"
#include "PID.h"
#include "bhs_SensorInput.h"
#include "Timer.h"

#define REAL_AUTO 0

class bhs_Autonomous {
public: 
		bhs_Autonomous(bhs_GlobalData*);
		~bhs_Autonomous();

		void init();
		void run();

	private:
		bhs_GlobalData* m_gd;
		typedef enum {
			k_intakeForward = 0,
			k_intakeReversed,
			k_tusksUp,
			k_tusksDown,
			k_finished
		} State;

		State m_state;
		Timer time;

		void reset();
		void testIntake();
};

#endif //BHS_AUTONOMOUS_H_
