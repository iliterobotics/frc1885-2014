#ifndef BHS_GLOBAL_DATA_H_
#define BHS_GLOBAL_DATA_H_

#include "bhs_Constants.h"
#include "bhs_GDDrivetrain.h"
<<<<<<< HEAD
#include <WPILib/Utility.h>

class bhs_GlobalData
	: public bhs_GDDrivetrain
{
	public:
		bhs_GlobalData();
		UINT32 cycleTime; // Current time in [milli-seconds] when the current code cycle began
=======
#include "bhs_GDIntake.h"
#include "bhs_GDTusks.h"
#include "bhs_GDShooter.h"

class bhs_GlobalData
	: public bhs_GDDrivetrain
	, public bhs_GDIntake
	, public bhs_GDTusks
	, public bhs_GDShooter
{
	public:
		bhs_GlobalData();
		
		bool mda_goalHot;	// TEMPORARY until data structure developed for comms and vision data
>>>>>>> origin/silut
};

#endif // BHS_GLOBAL_DATA_H_
