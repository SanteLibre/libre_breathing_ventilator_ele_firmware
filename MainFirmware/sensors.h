// sensors.h

#ifndef _SENSORS_h
#define _SENSORS_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

#define NUMBER_OF_SENSORS 3

typedef struct {
	uint8_t humidity;
	int8_t temperature;
	uint8_t pressure;
}t_sensors;


t_sensors* get_sensors();

uint8_t sensors_init();
uint8_t update_sensors();
#endif

