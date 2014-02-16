#if TUSK
#include "bhs_Compressor.h"

bhs_Compressor::bhs_Compressor(UINT32 p_channel) 
	: m_comp(p_channel)
{

}

bhs_Compressor::~bhs_Compressor() {
}

void bhs_Compressor::init() {
	m_comp.Start();
}

void bhs_Compressor::run() {
	if(!m_comp.Enabled()) {
		m_comp.Start();
	}
}
#endif	// TUSK
