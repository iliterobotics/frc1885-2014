#ifndef BHS_LIMIT_H
#define BHS_LIMIT_H

#include "WPILib/DigitalInput.h"

class bhs_Compressor {
public:

	/**
	 * Constructor for Limits.
	 * \param p_lower lower limit switch port number
	 * \param p_upper upper limit swtich port number
	 */
	bhs_Limit(UINT32 p_lower, UINT32 p_upper);

	/**
	 * Destructor.
	 */
	~bhs_Compressor();

	/**
	 * Returns if the lower limit switch has been hit
	 * \return if the lower limit switch has been hit
	 */
	bool atLower();

	/**
	 * Returns if the upper limit switch has been hit
	 * /return if the upper limit switch has been hit
	 */
	bool atUpper();

private:

	///The lower limit switch
	DigitalInput m_lower;

	///The upper limit switch
	DigitalInput m_upper;

};

#endif // BHS_LIMIT_H
