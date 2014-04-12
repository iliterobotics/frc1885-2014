#ifndef BHS_SHOOTER_H_
#define BHS_SHOOTER_H_

#include "Timer.h"

#include "bhs_GlobalData.h"

class bhs_Shooter {
	public:
		bhs_Shooter(bhs_GlobalData*);
		~bhs_Shooter();

		void run();
		
	private:
		bhs_GlobalData* m_ds;
		
		typedef enum {
			k_ready = 0,
			k_shoot,
			k_winch
		} ShootState;
		ShootState m_state;
		
		typedef enum {
			k_lowGoal = 0,
			k_wait,
			k_highGoal,
			k_finished
		} DoubleShotState;
		DoubleShotState m_doubleShotState;
		Timer* m_doubleShotTimer;
		
};
#endif
