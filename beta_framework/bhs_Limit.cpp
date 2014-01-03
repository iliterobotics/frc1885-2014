#include "bhs_Limit.h"

bhs_Limit::bhs_Limit(UINT32 p_lower, UINT32 p_upper) {
	m_lower = new DigitalInput(p_lower);
	m_upper = new DigitalInput(p_upper);
}

bhs_Limit::~bhs_Limit() {

}

bool bhs_Limit::atLower() {
	return m_lower.Get();
}

bool bhs_Limit::atUpper() {
	return m_upper.Get();
}