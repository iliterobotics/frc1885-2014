#ifndef BHS_AUTONOMOUS2_H_
#define BHS_AUTONOMOUS2_H_

#include <math.h>

#include "DriverStation.h"

#include "bhs_GlobalData.h"
#include "PID.h"
#include "bhs_SensorInput.h"
#include "Timer.h"

#define REAL_AUTO 0

class bhs_Autonomous2 {
public: 
		bhs_Autonomous2(bhs_GlobalData*);
		~bhs_Autonomous2();

		void init();
		void run();

	private:
		bhs_GlobalData* m_ds;
		typedef enum {
			k_wench = 0,
			k_lowGoalForward,
			k_highGoalRelease,
			k_finished
		} State;

		State m_state;
		Timer time;

		void reset();
		void testShooter();
};

#endif //BHS_AUTONOMOUS2_H_
