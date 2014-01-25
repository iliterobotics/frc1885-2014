#include "bhs_DriveAngle2.h"

bhs_DriveAngle2::bhs_DriveAngle2()
        : m_pid()
        , m_hasPrevAngle(false)
        , m_prevAngle(0)
{
        m_pid.init(0, 0, 0);
}

double bhs_DriveAngle2::setCurveFromAngles(float& a_curve, float a_desAngle, float a_curAngle) {
        double l_pidAddition = m_pid.apply(a_curAngle - a_desAngle);

        a_curve += l_pidAddition;

        return l_pidAddition;
}

double bhs_DriveAngle2::setLeftRightFromAngles(float& a_leftPower, float& a_rightPower, float a_desAngle, float a_curAngle) {
        double l_pidAddition = m_pid.apply(a_curAngle - a_desAngle);

        a_leftPower += l_pidAddition;
        a_rightPower -= l_pidAddition;

        return l_pidAddition;
}

void bhs_DriveAngle2::setPID(double a_p, double a_i, double a_d) {
        m_pid.init(a_p, a_i, a_d);
}

bool bhs_DriveAngle2::driveAngleFinished(float a_desAngle, float a_curAngle) {
        bool l_finished;
        if (m_hasPrevAngle) {
                l_finished = fabs(a_curAngle - m_prevAngle) < bhs_Constants::DRIVE_ANGLE_DIFF_THRESHOLD &&
                                fabs(a_curAngle - a_desAngle) < bhs_Constants::DRIVE_ANGLE_THRESHOLD;   
        } else {
                l_finished = false;
                m_hasPrevAngle = true;
        }
        m_prevAngle = a_curAngle;
        return l_finished;
}
