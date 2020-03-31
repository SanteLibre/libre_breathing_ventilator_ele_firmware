
#include "external_com.h"
#include "ui.h"
#include "sensors.h"

char print_buffer[250];

// the setup function runs once when you press reset or power the board
void setup() {
	//Serial.begin(115200);
	sensors_init();
	ext_com_init();
}

// the loop function runs over and over again forever
void loop() {

	update_sensors();
	send_sensors();
	delay(1000);
}
