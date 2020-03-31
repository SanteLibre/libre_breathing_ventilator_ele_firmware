// external_com.h

#ifndef _EXTERNAL_COM_h
#define _EXTERNAL_COM_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


uint8_t ext_com_init();
uint8_t send_sensors();
#endif

