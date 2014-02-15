#ifndef BHS_OUTPUT_MANAGER_H_
#define BHS_OUTPUT_MANAGER_H_

#include "Compressor.h"
#include "Talon.h"
#include "Relay.h"
#include "DoubleSolenoid.h"
#include "Solenoid.h"

#include "bhs_Constants.h"
#include "bhs_GlobalData.h"

class bhs_OutputManager {
        public:
                typedef enum MotorID { 
                };

                bhs_OutputManager(bhs_GlobalData*);
                ~bhs_OutputManager();

                void init();
                void run();

        private:
                bhs_GlobalData* m_gd;

                void safety();
                void runMotors();
                void runPneumatics();

#if COMPRESSOR
                Compressor m_compressor;
#endif        // COMPRESSOR
#if DRIVETRAIN
                Talon m_driveLeftB, m_driveRightB, m_driveLeftF, m_driveRightF;
#endif        // DRIVETRAIN
#if INTAKE
                Talon m_intakeRoller;
#endif        // INTAKEs
#if TUSKS
                /*DoubleSolenoid m_leftTusk, m_rightTusk;*/
                DoubleSolenoid m_tusks;
#endif        // TUSKS
#if SHOOTER
                Talon m_wench;
                Solenoid m_lowGoal;
                DoubleSolenoid m_highGoalRelease;
                
                Solenoid m_s6, m_s7, m_s8;
                
#endif        // SHOOTER
                
                
};

#endif //BHS_OUTPUT_MANAGER_H_
