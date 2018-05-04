#ifndef RC_SENSOR_H
#define RC_SENSOR_H

#include <SensorsInterface.h>
#include <Helper.h>

class RC : public Sensor{
public:
	RC() : controlling(false), timer(0), previousController(RETURNHOME_CONTROLLER){
		for(int i = 0; i < RC_NUM_CHANNELS; ++i){
			rc_values[i] = 0; rc_start[i] = 0;
		}
		offsetmin[0] = RC_1_MIN;
		offsetmax[0] = RC_1_MAX;
		offsetmin[1] = RC_2_MIN;
		offsetmax[1] = RC_2_MAX;
		offsetmin[2] = RC_3_MIN;
		offsetmax[2] = RC_3_MAX;
		offsetmin[3] = RC_4_MIN;
		offsetmax[3] = RC_4_MAX;
		offsetmin[4] = RC_5_MIN;
		offsetmax[4] = RC_5_MAX;
		offsetmin[5] = RC_6_MIN;
		offsetmax[5] = RC_6_MAX;
		}
		
	void init(){
	}
	void updateMeasures();
	void updateTest(){}
	void communicateData(){}
	
	void interruptCH(uint8_t channel, uint8_t pin);
	uint16_t getRawValue(uint8_t channel){if(channel < RC_NUM_CHANNELS) return rc_values[channel];}
	float getValue(uint8_t channel){if(channel < RC_NUM_CHANNELS) return mapf(rc_values[channel], offsetmin[channel], offsetmax[channel], 0.0, 1.0);}
	
private:
	uint16_t rc_values[RC_NUM_CHANNELS];
	uint32_t rc_start[RC_NUM_CHANNELS];
	
	bool controlling;
	
	unsigned long timer;
	unsigned long watchdog;
	unsigned int offsetmin[RC_NUM_CHANNELS];
	unsigned int offsetmax[RC_NUM_CHANNELS];
	
	int previousController;
};

#endif