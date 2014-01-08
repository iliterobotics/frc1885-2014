#ifndef BHS_TARGET_H
#define BHS_TARGET_H

#include "WPILib/AnalogChannel.h"
#include "WPILIb/DigitalInput.h"
#include "bhs_PID.h"

class bhs_Target {
public:
	static typedef enum {
		k_encoder = 0,
		k_potentiometer,
		k_gyro
	} TargetType;

	bhs_Taget(TargetType, UINT32);
	~bhs_Taget();

	float getCurrentPosition();
	float getPID(int);

private:
	AnalogChannel m_analog;
	DigitalInput m_digital;
	bhs_PID m_PID;
	
};

#endif // BHS_TARGET_H
