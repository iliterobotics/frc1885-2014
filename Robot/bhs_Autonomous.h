#ifndef BHS_AUTONOMOUS_H_
#define BHS_AUTONOMOUS_H_

#include <math.h>

#include "DriverStation.h"

#include "bhs_GlobalData.h"
#include "PID.h"
#include "bhs_SensorInput.h"
#include "Timer.h"

#define REAL_AUTO 1
#define AUTO 1

class bhs_Autonomous {
public:
	bhs_Autonomous(bhs_GlobalData*);
	virtual ~bhs_Autonomous();

	virtual void init();
	virtual void run();

private:
	void hotGoalForward();

	static const float k_maxVel = 0.8;
	static const int k_dist = 84;			// 180 inches, 15 feet
	static const int k_forwardDist = 180;	// 
	static const int k_pidThreshold1 = 2;

	void twoBall();
	typedef enum {
		k_forward = 0,
		k_waitHot,
		k_shoot,
		k_rearm,
		k_backward,
		k_intake,
		k_finished
	} State;
	static const int k_pidThreshold2 = 4;
	static const int k_forwardDist1 = -7 * 12;
	static const int k_backwardDist1 = 8 * 12 + 6;
	static const int k_forwardDist2 = -8 * 12 - 6;
	static const double k_winchWaitTime1 = .25;
	static const double k_winchWaitTime2 = 2.25;
#endif

	bhs_GlobalData* m_gd;
	State m_state;
	//PID m_straightPID; OLD used with gryos
	PID m_leftDistPID;
	PID m_rightDistPID;
	DriverStation* m_ds;
	Timer m_timer;
	bool m_secondBall;

#if not PRODUCTION_ROBOT
	static const float k_ticksPerInch = 15.691;
#endif

	void reset();
	int inchesToEncoder(float a_inches);
	float encoderToInches(int a_encoders);

	void moveStraight(int p_dist);

};
