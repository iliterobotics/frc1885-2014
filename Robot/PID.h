#ifndef PID_H
#define PID_H

#include "bhs_GlobalData.h"

class PID
{

public:

        PID ();
        ~PID ();
        void setConstants ( float P, float I, float D );
        void reset();
        float getPID ( float pv, float sp);

        
private:

        float getP () const;
        float getI ( float dt );
        float getD () const;

        float m_p, m_i, m_d;
        
        float m_error, m_previousError;
        float m_integral;
        
        bhs_GlobalData* m_globals;
};

#endif
