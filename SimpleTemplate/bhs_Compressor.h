#if TUSK

#ifndef BHS_COMPRESSOR_H
#define BHS_COMPRESSOR_H

#include "Compressor.h"

class bhs_Compressor {
public:
	bhs_Compressor(UINT32 p_channel);
	~bhs_Compressor();

	void init();
	void run();

private:
	Compressor m_comp;

};

#endif // BHS_COMPRESSOR_H

#endif	// TUSK
