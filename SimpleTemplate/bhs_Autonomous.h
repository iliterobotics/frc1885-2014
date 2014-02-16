#ifndef BHS_AUTONOMOUS_H_
#define BHS_AUTONOMOUS_H_

#include <math.h>

#include "DriverStation.h"
#include "Timer.h"

#include "bhs_GlobalData.h"
#include "PID.h"
#include "bhs_SensorInput.h"

#define REAL_AUTO 1

class bhs_Autonomous {
public:
	bhs_Autonomous(bhs_GlobalData*);
	virtual ~bhs_Autonomous();

	virtual void init();
	virtual void run();

private:
	typedef enum {
		k_forward = 0,
		k_waitHot,
		k_shoot,
		k_rearm,
		k_backward,
		k_intake,
		k_finished
	} State;

	bhs_GlobalData* m_gd;
	State m_state;
	PID m_distPID;
	PID m_straightPID;
	Timer m_timer;
	bool m_secondBall;

	static const float k_maxVel = 0.8;
	static const int k_pidThreshold = 2;
	static const int k_forwardDist1 = -4 * 12;
	static const int k_backwardDist1 = 5 * 12;
	static const int k_forwardDist2 = -5 * 12;
	static const double k_winchWaitTime = 4;

	void reset();
	int inchesToEncoder(float a_inches);
	float encoderToInches(int a_encoders);

	void hotGoalForward();
	void twoBallAuto();
};

#endif //BHS_AUTONOMOUS_H_
