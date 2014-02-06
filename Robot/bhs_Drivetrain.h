#ifndef BHS_DRIVETRAIN_H_
#define BHS_DRIVETRAIN_H_

#include <math.h>

#include "bhs_Constants.h"
<<<<<<< HEAD
#include "bhs_GlobalData.h"
#include "bhs_PID.h"
=======
#include "bhs_GDDrivetrain.h"
#include "PID.h"
>>>>>>> origin/silut

class bhs_DriveTrain  {
	public:
		bhs_DriveTrain(bhs_GDDrivetrain*);
		~bhs_DriveTrain();

		void init();
		void run();

	private:
		bhs_GDDrivetrain* m_dd;
		PID m_driveStraightPID;

		void tankDrive();
		void arcadeDrive();
			void driveStraight();
				void driveStraightReset();

		float limit(float);
		float deadzone(float);

};

#endif //BHS_DRIVETRAIN_H_
