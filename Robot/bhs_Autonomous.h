#ifndef BHS_AUTONOMOUS_H_
#define BHS_AUTONOMOUS_H_

#include <math.h>

#include <DriverStation.h>
#include "Timer.h"

#include "bhs_GlobalData.h"

class bhs_Autonomous {
	public:
		bhs_Autonomous(bhs_GlobalData*);
		virtual ~bhs_Autonomous();

		virtual void init();
		virtual void run();
		
	private:
		typedef enum {
			k_forward = 0,
			k_finished
			// ...
		} State;
		
		bhs_GlobalData* m_gd;
		State m_state;

		Timer m_timer;

		void reset();
		int inchesToEncoder(float a_inches);
		void moveForward15();
};

#endif //BHS_AUTONOMOUS_H_
