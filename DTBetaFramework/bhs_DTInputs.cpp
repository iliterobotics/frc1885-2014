#include "bhs_DTInputs.h"

bhs_DTInputs::bhs_DTInputs()
	: m_joyLeft(1)
	, m_joyRight(2)
{
}

bhs_DTInputs::~bhs_DTInputs() {
}

float bhs_DTInputs::getY1() {
	return m_joyLeft.GetY();
}

float bhs_DTInputs::getY2() {
	return m_joyRight.GetY();
}
