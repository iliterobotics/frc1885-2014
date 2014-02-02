#ifndef BHS_OUTPUT_MANAGER_H_
#define BHS_OUTPUT_MANAGER_H_

#include "Compressor.h"
#include "Talon.h"
#include "Solenoid.h"
#include "Relay.h"

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
#endif	// COMPRESSOR
#if DRIVETRAIN
		Talon m_driveLeftB, m_driveRightB;
#if PRODUCTION_ROBOT
		Talon m_driveLeftF, m_driveRightF;
#endif
#endif	// DRIVETRAIN
#if INTAKE
		Talon m_intakeRoller;
#endif	// INTAKE
#if TUSKS
		DoubleSolenoid m_leftTusk, m_rightTusk;
#endif	// TUSKS
		
		bool* m_reversedMotors;
};

#endif //BHS_OUTPUT_MANAGER_H_
