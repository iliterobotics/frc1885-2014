#ifndef BHS_DRIVE_ANGLE_2_H
#define BHS_DRIVE_ANGLE_2_H

#include "math.h"

#include "bhs_Constants.h"
#include "bhs_PID.h"

class bhs_DriveAngle2 {
public:
        bhs_DriveAngle2();

        void setPID(double, double, double);
        double setCurveFromAngles(float&, float, float);
        double setLeftRightFromAngles(float&, float&, float, float);
        bool driveAngleFinished(float, float);
        
private:
        bhs_PID m_pid;
        
        bool m_hasPrevAngle;
        float m_prevAngle;
        
};

#endif
