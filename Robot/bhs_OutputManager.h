#ifndef BHS_OUTPUT_MANAGER_H_
#define BHS_OUTPUT_MANAGER_H_

#include "Talon.h"
#include "Solenoid.h"
#include "Relay.h"

#include "bhs_Constants.h"
#include "bhs_GlobalData.h"

class bhs_OutputManager {
	public:
		static const UINT32 K_DRIVE_LEFT_B = 1;
		static const UINT32 K_DRIVE_RIGHT_B = 2;
		
		// Constant declarations go here.

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
		
		Talon m_driveLeftB, m_driveRightB;
		
		bool* m_reversedMotors;

		// Talon, Solenoid, and Relay declarations go here
};

#endif //BHS_OUTPUT_MANAGER_H_
