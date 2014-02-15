#ifndef BHS_GD_INTAKE_H_
#define BHS_GD_INTAKE_H_

#include "bhs_Constants.h"
#include "DoubleSolenoid.h"

class bhs_GDIntake {
public:
	bhs_GDIntake();

	bool mdi_intakeForward;
	bool mdi_intakeReversed;
	float mdi_intakeOutput;
	static const float mdi_maxForwardPower = 0.95;
	static const float mdi_maxReversedPower = -0.95;

	bool mdt_tusksUp;
	bool mdt_tusksDown;
	DoubleSolenoid::Value mdt_tusksOutput;


};

#endif //BHS_GD_INTAKE_H_

