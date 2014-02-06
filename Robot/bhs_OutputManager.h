#ifndef BHS_OUTPUT_MANAGER_H_
#define BHS_OUTPUT_MANAGER_H_

#include "Talon.h"
#include "Relay.h"
#include "DoubleSolenoid.h"
#include "Solenoid.h"

#include "bhs_Constants.h"
#include "bhs_GlobalData.h"

class bhs_OutputManager {
<<<<<<< HEAD
	public:
		static const UINT32 K_DRIVE_LEFT_B = 1;
		static const UINT32 K_DRIVE_RIGHT_B = 2;
		
		// Constant declarations go here.

		typedef enum MotorID { 
		};
=======
        public:
                typedef enum MotorID { 
                };
>>>>>>> origin/silut

                bhs_OutputManager(bhs_GlobalData*);
                ~bhs_OutputManager();

                void init();
                void run();

        private:
                bhs_GlobalData* m_gd;

<<<<<<< HEAD

		void safety();
		void runMotors();
		void runPneumatics();
		
		Talon m_driveLeftB, m_driveRightB;
		
		bool* m_reversedMotors;

		// Talon, Solenoid, and Relay declarations go here
=======
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
#endif        // INTAKE
#if TUSKS
                DoubleSolenoid m_leftTusk, m_rightTusk;
#endif        // TUSKS
#if SHOOTER
                Relay m_wench;
                DoubleSolenoid m_lowGoal;
                Solenoid m_highGoalRelease;
#endif        // SHOOTER
>>>>>>> origin/silut
};

#endif //BHS_OUTPUT_MANAGER_H_
