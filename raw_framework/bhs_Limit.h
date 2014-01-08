#ifndef BHS_LIMIT_H
#define BHS_LIMIT_H

#include "WPILib/AnalogChannel.h"

class bhs_Compressor {
public:
	bhs_Limit(UINT32, UINT32);
	~bhs_Compressor();

	bool atLower();
	bool atUpper();

private:
	AnalogInput m_lower, m_upper;

};

#endif // BHS_LIMIT_H
