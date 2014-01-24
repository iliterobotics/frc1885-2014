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
		} State;
		
		bhs_GlobalData* m_gd;
		State m_state;
		PID m_straightPID;
		
#if not PRODUCTION_ROBOT
		static const float k_ticksPerInch = 15.691;
#endif
		
		static const float k_maxVel = 0.8;
		static const int k_dist = 180;			// 180 inches, 15 feet
		static const int k_pidThreshold = 0;

		void reset();
		int inchesToEncoder(float a_inches);
		float encoderToInches(int a_encoders);

		void pidAuto();
};

#endif //BHS_AUTONOMOUS_H_
