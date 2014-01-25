
#include <sockLib.h>
#include <inetLib.h>
#include "bhs_Telemetry.h"

bhs_Telemetry::bhs_Telemetry()
{
    this->sockFd = -1;
}

int bhs_Telemetry::connect(String host, u_short port)
{
    u_long addr;
    struct sockaddr_in saddr;
    
    this->m_sockFd = socket(AF_INET, SOCK_STREAM, 0);
    if (this->m_sockFd == ERROR)
        return -1;

    saddr.sin_addr.s_addr = inet_addr(host);
    saddr.sin_family = AF_INET;
    saddr.sin_port = htons(port);

    if (connect(this->m_sockFd, (struct sockaddr *) &saddr.
    		sizeof(saddr)) != OK) 
    {
    	return -1;
	close(this->sockFd);
	this->sockFd = -1;
    }

    return 0;
}

struct wire_data {
    // Order here matters and must match driver station code.
    int seq;

    // GD_DRIVETRAIN_H
    float mdd_joystick1X;
    float mdd_joystick1Y;
    float mdd_joystick2X;
    float mdd_joystick2Y;
    bool mdd_buttonUseArcade;
    bool mdd_arcadeDrive;
    float mdd_gyroAngle;
    float mdd_gyroBiasVoltage;
    int mdd_encoderCounts;
    bool mdd_startDriveAngle;
    bool mdd_stopDriveAngle;
    float mdd_desiredAngle;
    float mdd_driveAnglePIDAddition;
    float mdd_driveAngleTimer; // double
    float mdd_driveLeftPower;
    float mdd_driveRightPower;

    // GD_INTAKE_H
    bool mdi_intakeForward;
    bool mdi_intakeReversed;
    float mdi_intakePower;

    // GD_TUSKS_H
    int mdt_leftTuskOutput;	// enum
    int mdt_rightTuskOutput;	// enum

    // other data goes  here...
}
   

void dataExchange(bhs_GlobalData *a_gd, struct wire_data *wd) 
{
    // Order of assignment doesn't matter here.

#define ASSIGN(FLD) \
    wd->FLD = a_gd->FLD;
    wd->seq = 0xF00F; // magic

    // GD_DRIVETRAIN_H
    ASSIGN(mdd_joystick1X);
    ASSIGN(mdd_joystick1Y);
    ASSIGN(mdd_joystick2X);
    ASSIGN(mdd_joystick2Y);
    ASSIGN(mdd_buttonUseArcade);
    ASSIGN(mdd_arcadeDrive);
    ASSIGN(mdd_gyroAngle);
    ASSIGN(mdd_gyroBiasVoltage);
    ASSIGN(mdd_encoderCounts);
    ASSIGN(mdd_startDriveAngle);
    ASSIGN(mdd_stopDriveAngle);
    ASSIGN(mdd_desiredAngle);
    ASSIGN(mdd_driveAnglePIDAddition);
    ASSIGN(mdd_driveAngleTimer);
    ASSIGN(mdd_driveLeftPower);
    ASSIGN(mdd_driveRightPower);
    ASSIGN(m_minSpeedKinetic);
    ASSIGN(m_minSpeedStatic);

    // GD_INTAKE_H

    ASSIGN(mdi_intakeForward);
    ASSIGN(mdi_intakeReversed);
    ASSIGN(mdi_intakePower);

    // GD_TUSKS_H

    ASSIGN(mdt_tusksUp);
    ASSIGN(mdt_tusksDown);
    ASSIGN(mdt_leftTuskOutput);
    ASSIGN(mdt_rightTuskOutput);
}

int bhs_Telemetry::transfer(bhs_GlobalData *a_gd)
{
    struct wire_data wd;
    int ns; 
    dataExchange(a_gd, &wd);
    // FIXME: safe_send(...)
    ns = send(this->m_sockFd, &wd, sizeof(wd), 0);
    if (ns == ERROR)
        return -1;
    return 0;	
}

void bhs_Telemetry::disconnect(void)
{
    close(self->m_sockFd);
}
