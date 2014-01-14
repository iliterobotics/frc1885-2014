#include "bhs_Drivetrain.h"

bhs_Drivetrain::bhs_Drivetrain(UINT32 p_left, UINT32 p_right)
	: m_inputs()
	, m_dtLeft(p_left, 0.8)
	, m_dtRight(p_right, 0.8)
{
}

bhs_Drivetrain::~bhs_Drivetrain() {
}

void bhs_Drivetrain::init() {
}

void bhs_Drivetrain::run() {
	tankDrive(m_inputs.getY1(), m_inputs.getY2());
}

void bhs_Drivetrain::tankDrive(float p_left, float p_right) {
	m_dtLeft.move(p_left);
	m_dtRight.move(p_right);
}
