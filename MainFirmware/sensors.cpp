// 
// 
// 

#include "sensors.h"

t_sensors sensors;

t_sensors* get_sensors() {
	return &sensors;
}

uint8_t sensors_init() {
	memset(&sensors, 0, sizeof(sensors));
	return 0;
}

uint8_t update_sensors() {
	sensors.humidity += 5;
	sensors.pressure += 8;
	sensors.temperature += 1;

	return 0;
}

