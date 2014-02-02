#ifndef BHS_GD_SHOOTER_H_
#define BHS_GD_SHOOTER_H_

#include "bhs_Constants.h"

class bhs_GDShooter {
public:
        bhs_GDShooter();

        bool mds_mFoward;
        bool mds_mBackward;
        bool mds_pOn;

        Relay::Value mds_motorOutput;
};

#endif        // BHS_GD_SHOOTER_H_