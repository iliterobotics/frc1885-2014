#ifndef BHS_COMPRESSOR_H
#define BHS_COMPRESSOR_H

#include "WPILib/Compressor.h"

class bhs_Compressor {
public:
	bhs_Compressor();
	~bhs_Compressor();

	void init();
	void run();

private:
	Compressor m_comp;

};

#endif // BHS_COMPRESSOR_H
