#include "bhs_Limit.h"

/**
 * Constructor for Limits.
 * \param p_lower lower limit
 * \param p_upper upper limit
 */
bhs_Limit::bhs_Limit(UINT32 p_lower, UINT32 p_upper) {
	m_lower = new DigitalInput(p_lower);
	m_upper = new DigitalInput(p_upper);
}

/**
 * Destructor.
 * Destructs the Limit
 */
bhs_Limit::~bhs_Limit() {

}

/**
 * Returns if the Limit is at its lowest.
 * \return if the limit is at its lowest
 */
bool bhs_Limit::atLower() {
	return m_lower.Get();
}

/**
 * Returns if the Limit is at its peak.
 * \return if the limit is at its peak
 */
bool bhs_Limit::atUpper() {
	return m_upper.Get();
}