#ifndef BHS_GLOBAL_DATA_H_
#define BHS_GLOBAL_DATA_H_

#include "bhs_Constants.h"
#include "bhs_GDDrivetrain.h"
#include "bhs_GDIntake.h"
#include "bhs_GDTusks.h"

class bhs_GlobalData
	: public bhs_GDDrivetrain
	, public bhs_GDIntake
	, public bhs_GDTusks
{
	public:
		bhs_GlobalData();
};

#endif // BHS_GLOBAL_DATA_H_
