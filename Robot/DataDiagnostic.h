#ifndef BHS_DATA_DIAG_H
#define BHS_DATA_DIAG_H
#include "bhs_PCDataServer.h"

//define macro to easily print
#define debug(text,...) RobotDebug::getInstance().print(text,__VA_ARGS__)

namespace {
	struct GamePadData {
		float x;
		float y;
		float z;
		int buttons[10];
	};

	struct JoystickData {
		float x;
		float y;
		float z;
		int buttons[11];
	};

	/*
	 * RobotTelemetry data
	 */
	struct RobotTelemetryData {
		int time;
		//float batteryVoltage;
		float pwmOutputs[10];
		int relayOutputs[8];
		float digitalInputs[14];
		float analogInputs[8];
		int pneumatics[8];
		struct JoystickData joysticks[2];
		struct GamePadData gamepads[1];
	};

}


/*
 * RobotTelemetry class
 * 	-Object and Translator for Robot Diagnostics
 * 	-Each field is 4 bytes:
 * 	[id][length][time][pwms][relays][dio][aio][pnio][joysticks][gamepads]
 */
class RobotTelemetry {
	public:
		/*
		 * Singleton Pattern
		 */
		static RobotTelemetry& getInstance()
		{
			static RobotTelemetry instance;
			return instance;
		}
	
		virtual ~RobotTelemetry(void);

		virtual int getId();
		virtual long getLength();
		virtual char* getEncoded();
		virtual RobotTelemetryData* getDecoded(char*);
		
		/*
		 * Update send rate
		 */
		virtual void updateSendRate(long);
		
		/*
		 * Enable/Disable telemetry sending
		 */
		virtual void enable();
		virtual void disable();

		/*
		 * getter for diagnostics
		 */
		virtual RobotTelemetryData* getDiagnostics() { return robotDiagnostics; }

	private:
		static const int id = 0xDA7AFEED;
		
		RobotTelemetry();
		static int start(RobotTelemetry* apThis);
		void updateTelemetryData();
		void scheduledSend();
		
		/*
		 * struct to hold the data
		 */
		RobotTelemetryData* robotDiagnostics;
		virtual void initTelemetryData();
		
		
		/*
		 * Send rate
		 */
		long sendRate;
		
		/*
		 * enable/disable
		 */
		bool isEnabled;
		
		/*
		 * Semaphore for updating RobotTelemetry
		 */
		SEM_ID mRobotTelemetry;
		
		/*
		 * start time
		 */
		long startTime;
		
};

/*
 * RobotDebug class
 * 	-used to send debug off the robot to the driver station
 */
class RobotDebug {
	public:
	
		/*
		 * Singleton Pattern
		 */
		static RobotDebug& getInstance()
		{
			static RobotDebug instance;
			return instance;
		}
	
		virtual ~RobotDebug();
		
		/*
		 * enable/disable
		 */
		virtual void setEnabled(bool);
		
		/*
		 * print the char array back to the driver station
		 */
		virtual void print(const char* format, ...);
	
	private:
		RobotDebug();

		/*
		 * debug code
		 */
		static const int id = 0xD3B6FEED;
		bool isEnabled;
		
		/*
		 * Semaphore for writing
		 */
        SEM_ID mPrintData;
        
        /*
         * Semaphore for enabling/disabling
         */
        SEM_ID mEnablePrint;
        
};

#endif
