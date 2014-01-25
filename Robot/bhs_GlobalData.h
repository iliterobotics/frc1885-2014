#ifndef BHS_GLOBAL_DATA_H_
#define BHS_GLOBAL_DATA_H_

#include "bhs_Constants.h"
#include "bhs_GDDrivetrain.h"
#include <Utility>

class bhs_GlobalData
	: public bhs_GDDrivetrain
{
	public:
		bhs_GlobalData();
		UINT32 cycleTime; // Current time in [milli-seconds] when the current code cycle began
};

#endif // BHS_GLOBAL_DATA_H_
