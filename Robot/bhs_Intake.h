#ifndef BHS_INTAKE_H_
#define BHS_INTAKE_H_

#include "bhs_Constants.h"
#include "bhs_GDIntake.h"

class bhs_Intake  {
	public:
		bhs_Intake(bhs_GDIntake*);
		//~bhs_Intake();

		void run();

	private:
		bhs_GDIntake* m_di;
};

#endif //BHS_INTAKE_H_
