#ifndef BHS_SENSOR_INPUT_H_
#define BHS_SENSOR_INPUT_H_

#include "Encoder.h"
<<<<<<< HEAD
=======
#include "Gyro.h"
#include "DigitalInput.h"
>>>>>>> origin/silut

#include "bhs_Constants.h"
#include "bhs_GlobalData.h"

using namespace std;

class bhs_SensorInput {
	public:
		// analog inputs
		// static const UINT32 _CHANNEL;
		// ...
		
		// digital inputs
		// static const UINT32 _CHANNEL;
		// ...
		
		bhs_SensorInput(bhs_GlobalData*);
		~bhs_SensorInput();

		void init();
		void run();

	private:
		bhs_GlobalData* m_gd;

		// Sensor declarations go here
<<<<<<< HEAD
		Encoder m_encoder;

=======
		Encoder m_leftEncoder;
#if TWO_ENCODERS
		Encoder m_rightEncoder;
#endif
		Gyro m_gyro;
#if SHOOTER
		DigitalInput m_wenchLimitSwitch;
#endif
>>>>>>> origin/silut
};

#endif //BHS_SENSOR_INPUT_H_
