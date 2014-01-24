#ifndef BHS_GD_INTAKE_H_
#define BHS_GD_INTAKE_H_

#include "bhs_Constants.h"

class bhs_GDIntake {
public:
	bhs_GDIntake();

	bool mdi_intakeForward;
	bool mdi_intakeReversed;

	float mdi_intakePower;

	static const float mdi_maxForwardPower = 0.8;
	static const float mdi_maxReversedPower = -0.8;


};

#endif //BHS_GD_INTAKE_H_

