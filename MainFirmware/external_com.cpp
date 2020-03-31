// 
// 
// 

#include "external_com.h"
#include "sensors.h"

#define BAUD_RATE 155200

char buffer[250];

char* to_json(t_sensors*);

uint8_t ext_com_init() {
	Serial.begin(115200);
	return 0;
}

uint8_t send_sensors() {
	t_sensors *sensors = get_sensors();
	char* json = to_json(sensors);
	Serial.println(json);
	return 0;
}

char* to_json(t_sensors *sensors) {
	sprintf(buffer, "{\"humidity\": %u, \"pressure\": %u, \"temperature\": %d}", 
		sensors->humidity, sensors->pressure, sensors->temperature);
	return buffer;
}
