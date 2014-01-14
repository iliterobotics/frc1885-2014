#include "bhs_PID.h"

bhs_PID::bhs_PID()
	: m_pMult(0.0)
	, m_iMult(0.0)
	, m_dMult(0.0)
	, m_cumulError(0.0)
	, m_prevError(0.0)
	, m_firstRun(true)
	, m_useMaxCumul(false)
	, m_maxCumul(0.0)
{
}

void bhs_PID::reset() {
	m_cumulError = 0.0;
	m_prevError = 0.0;
	m_firstRun = true;
}

void bhs_PID::init(double a_pMult, double a_iMult, double a_dMult) {
	m_pMult = a_pMult;
	m_iMult = a_iMult;
	m_dMult = a_dMult;
	m_useMaxCumul = false;
}

void bhs_PID::setMaxCumul(double a_maxCumul) {
	m_useMaxCumul = true;
	m_maxCumul = a_maxCumul;
}

double bhs_PID::apply(double a_error) {
	double l_p = 0.0;
	double l_i = 0.0;
	double l_d = 0.0;
	
	l_p = m_pMult * a_error;
	
	m_cumulError += a_error;
	if (m_useMaxCumul) {
		if (m_cumulError > m_maxCumul) {
			m_cumulError = m_maxCumul;
		} else if (m_cumulError < -m_maxCumul) {
			m_cumulError = -m_maxCumul;
		}
	}
	l_i = m_iMult * m_cumulError;
	
	if (m_firstRun) {
		m_firstRun = false;
	} else {
		l_d = m_dMult * (a_error - m_prevError);
	}
	
	m_prevError = a_error;
	
	return l_p + l_i + l_d;
}

double bhs_PID::getP() {
	return m_pMult;
}

double bhs_PID::getD() {
	return m_dMult;
}
