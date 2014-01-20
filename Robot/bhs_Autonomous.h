#ifndef BHS_AUTONOMOUS_H_
#define BHS_AUTONOMOUS_H_

#include <math.h>

#include "DriverStation.h"

#include "bhs_GlobalData.h"
#include "PID.h"

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
		PID m_straightPID;
		
		static const float k_velDiff = 0.005;
		static const float k_maxVel = 0.8;
		static const int k_dist = 200;
		static const int k_pidThreshold = 0;
		int m_encoderMarker;

		void reset();
		int inchesToEncoder(float a_inches);
		float encoderToInches(int a_encoders);

		void moveForward15();
		void trapezoidal();
		void pidAuto();
};

#endif //BHS_AUTONOMOUS_H_
