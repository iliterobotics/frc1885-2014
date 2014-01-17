#ifndef BHS_SENSOR_INPUT_H_
#define BHS_SENSOR_INPUT_H_

#include "Encoder.h"
#include "Gyro.h"

#include "bhs_Constants.h"
#include "bhs_GlobalData.h"

using namespace std;

class bhs_SensorInput {
	public:
		
		bhs_SensorInput(bhs_GlobalData*);
		~bhs_SensorInput();

		void init();
		void run();

	private:
		bhs_GlobalData* m_gd;

		// Sensor declarations go here
		Encoder m_encoder;
		
		Gyro m_gyro;

};

#endif //BHS_SENSOR_INPUT_H_
