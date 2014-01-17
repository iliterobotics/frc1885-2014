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
				k_accel,
				k_constVel,
				k_decel,
			k_finished
			// ...
		} State;
		
		bhs_GlobalData* m_gd;
		State m_state;

		Timer m_timer;
		
		static const float k_velDiff = 0.005;
		static const float k_maxVel = 0.8;
		static const int k_dist = 180;
		int m_encoderMarker;

		void reset();
		int inchesToEncoder(float a_inches);

		void moveForward15();
		void trapezoidal();
};

#endif //BHS_AUTONOMOUS_H_
