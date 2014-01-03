#ifndef BHS_LIMIT_H
#define BHS_LIMIT_H

#include "WPILib/AnalogChannel.h"

class bhs_Compressor {
public:

	/**
	 * Constructor for Limits.
	 * \param p_lower lower limit
	 * \param p_upper upper limit
	 */
	bhs_Limit(UINT32 p_lower, UINT32 p_upper);

	/**
	 * Destructor.
	 * Destructs the Limit
	 */
	~bhs_Compressor();

	/**
	 * Returns if the Limit is at its lowest.
	 * \return if the limit is at its lowest
	 */
	bool atLower();

	/**
	 * Returns if the limit is at its peak.
	 * /return if the limit is at its peak
	 */
	bool atUpper();

private:

	///The Limit's lower limit
	DigitalInput m_lower;

	///The Limit's highest limit
	DigitalInput m_upper;

};

#endif // BHS_LIMIT_H
