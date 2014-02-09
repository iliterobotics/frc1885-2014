#include "bhs_GDIntake.h"

bhs_GDIntake::bhs_GDIntake() {
	mdi_intakeForward = false;
	mdi_intakeReversed = false;
	mdi_intakeOutput = 0.0;

	mdt_tusksUp = false;
	mdt_tusksDown = false;
	mdt_tusksOutput = true;
}
