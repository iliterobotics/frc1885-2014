#ifndef BHS_AUTONOMOUS_H_
#define BHS_AUTONOMOUS_H_

#include <math.h>

#include "DriverStation.h"

#include "bhs_GlobalData.h"
#include "PID.h"
#include "Timer.h"
#include "bhs_SensorInput.h"

#define REAL_AUTO 1

class bhs_Autonomous : public DriverStation {
public:
	bhs_Autonomous(bhs_GlobalData*);
	virtual ~bhs_Autonomous();

	virtual void init();
	virtual void run();

private:
	typedef enum {
		k1_forward = 0,
		k1_turn = 0,
		k1_waitHot,
		k1_shoot,
		k1_finished
	} OneBallState;

	typedef enum {
		k2_forward = 0,
		k2_waitHot,
		k2_shoot,
		k2_rearm,
		k2_backward,
		k2_intake,
		k2_finished
	} TwoBallState;

	bhs_GlobalData* m_gd;
	OneBallState m_oneBallState;
	TwoBallState m_twoBallState;
	PID m_distPID;
	PID m_straightPID;
	Timer m_timer;
	
	//DriverStation* m_driverStation;
	bool m_secondBall;

#if not PRODUCTION_ROBOT
	static const float k_ticksPerInch = 15.691;
#endif

	static const float k_maxVel = 0.8;
	static const int k_pidThreshold = 6;
	static const int k_forwardDist1 = -7 * 12;
	static const int k_backwardDist1 = 8 * 12;
	static const int k_forwardDist2 = -8 * 12;
	static const double k_winchWaitTime1 = .25;
	static const double k_winchWaitTime2 = 2;
	
	static const int k_dSButton = 1;

	void resetDT();
	int inchesToEncoder(float a_inches);
	float encoderToInches(int a_encoders);

	void moveStraight(int p_dist);
	void oneBall();
	void twoBall();
};

#endif //BHS_AUTONOMOUS_H_
