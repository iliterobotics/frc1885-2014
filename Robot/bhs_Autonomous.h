#ifndef BHS_AUTONOMOUS_H_
#define BHS_AUTONOMOUS_H_

#include <math.h>

#include "DriverStation.h"
#include "Timer.h"

#include "bhs_GlobalData.h"
#include "PID.h"
#include "bhs_SensorInput.h"

#define TWO_BALL_1 0

class bhs_Autonomous {
public:
	bhs_Autonomous(bhs_GlobalData*);
	virtual ~bhs_Autonomous();

	virtual void init();
	virtual void run();

private:
#if TWO_BALL_1
	typedef enum {
		k_forward = 0,
		k_waitHot,
		k_shoot,
		k_rearm,
		k_backward,
		k_intake,
		k_finished
	} State;
#else
	typedef enum {
		k_startTimer = 0,
		k_intakeUp,
		k_backward,
		k_forward,
		k_shoot1,
		k_winch,
		k_intakeDown,
		k_shoot2,
		k_finished
	} State;
#endif

	bhs_GlobalData* m_gd;
	State m_state;
	PID m_distPID;
	PID m_straightPID;
	Timer m_timer;
	bool m_secondBall;

	static const float k_maxVel = 0.8;
#if TWO_BALL_1
	static const int k_pidThreshold = 6;
	static const int k_forwardDist1 = -7 * 12;
	static const int k_backwardDist1 = 8 * 12;
	static const int k_forwardDist2 = -8 * 12;
	static const double k_winchWaitTime1 = .25;
	static const double k_winchWaitTime2 = 2;
#else
	static const int k_pidThreshold = 4;
	static const int k_backwardDist = 1 * 12;
	static const int k_forwardDist = -8 * 12;
	static const double k_intakeWait = 0.5;
	static const double k_shootWait = 0.25;
#endif

	void resetDT();
	int inchesToEncoder(float a_inches);
	float encoderToInches(int a_encoders);

#if TWO_BALL_1
	// Forward, shoot, back, pickup, forward, shoot
	void twoBall1();
#else
	// Back, pickup, forward, shoot, shoot
	void twoBall2();
#endif
};

#endif //BHS_AUTONOMOUS_H_
