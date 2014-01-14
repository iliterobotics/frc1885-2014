#ifndef BHS_DRIVETRAIN_H
#define BHS_DRIVETRAIN_H

#include "bhs_Manipulator.h"
#include "bhs_DTInputs.h"
#include "bhs_Talon.h"

class bhs_Drivetrain {
public:
	bhs_Drivetrain(UINT32 p_left, UINT32 p_right);
	~bhs_Drivetrain();

	void init();
	void run();

private:
	void tankDrive(float p_left, float p_right);

	bhs_DTInputs m_inputs;
	bhs_Talon m_dtLeft, m_dtRight;
};


#endif // BHS_DRIVETRAIN_H
