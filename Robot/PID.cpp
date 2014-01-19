#include "PID.h"

PID :: PID ()
{
	m_error = m_integral = 0.0;
}

PID :: ~PID ()
{

}

void PID :: setConstants (const float p_p, const float p_i, const float p_d )
{
	m_p = p_p;
	m_i = p_i;
	m_d = p_d;
}

void PID::reset() {
	m_error = 0;
	m_previousError = 0;
	m_integral = 0;
}

float PID :: getPID (const float pv, const float sp)
{
	m_previousError = m_error;
	m_error = sp - pv;

	return (m_p * getP()) + (m_i * getI(1.0)) + (m_d * getD());
}

float PID :: getP () const
{
	return m_error;
}

float PID :: getI (const float dt )
{
	return m_integral+= m_error * dt;
}

float PID :: getD () const
{
	return m_error - m_previousError;
}
