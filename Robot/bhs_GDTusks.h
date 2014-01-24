#ifndef BHS_GD_TUSKS_H_
#define BHS_GD_TUSKS_H_

#include "DoubleSolenoid.h"

#include "bhs_Constants.h"

class bhs_GDTusks {
public:
	bhs_GDTusks();

	bool mdt_tusksUp;
	bool mdt_tusksDown;

	DoubleSolenoid::Value mdt_leftTuskOutput;
	DoubleSolenoid::Value mdt_rightTuskOutput;

};

#endif	// BHS_GD_TUSKS_H_
