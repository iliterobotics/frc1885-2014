#ifndef BHS_SHOOTER_H_
#define BHS_SHOOTER_H_

#include "bhs_GDShooter.h"

class bhs_Shooter {
	public:
		bhs_Shooter(bhs_GDShooter*);
		~bhs_Shooter();

		void run();
		
	private:
		bhs_GDShooter* m_ds;
};
#endif
