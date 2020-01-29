/*
 * Lights.cpp
 *
 *  Created on: Jan 22, 2020
 *      Author: josop
 */

#include "Lights.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

#define taskDelay_ms(ms)	vTaskDelay(ms / portTICK_PERIOD_MS )

#define SLOW_TIME	400
#define FAST_TIME	200

Lights::Lights(Led & led1, Led & led2)
	: m_led1(led1)
	, m_led2(led2)
	, m_mode((Mode) 0)
{
	// TODO Auto-generated constructor stub

}

Lights::~Lights() {
	// TODO Auto-generated destructor stub
}

void Lights::nextMode() {
	switch(m_mode){

	case SLOW_SAME:
		m_mode = FAST_SAME;
		break;

	case FAST_SAME:
		m_mode = SLOW_DIFFERENT;
		break;

	case SLOW_DIFFERENT:
		m_mode = FAST_DIFFERENT;
		break;

	case FAST_DIFFERENT:
		m_mode = SLOW_SAME;
		break;
	}
}

void Lights::executeModePhase() {
	switch(m_mode){

	case SLOW_SAME:
		m_led1.turnON();
		m_led2.turnON();
		taskDelay_ms(SLOW_TIME);

		m_led1.turnOFF();
		m_led2.turnOFF();
		taskDelay_ms(SLOW_TIME);
		break;

	case FAST_SAME:
		m_led1.turnON();
		m_led2.turnON();
		taskDelay_ms(FAST_TIME);

		m_led1.turnOFF();
		m_led2.turnOFF();
		taskDelay_ms(FAST_TIME);
		break;

	case SLOW_DIFFERENT:
		m_led1.turnON();
		m_led2.turnOFF();
		taskDelay_ms(SLOW_TIME);

		m_led1.turnOFF();
		m_led2.turnON();
		taskDelay_ms(SLOW_TIME);
		break;

	case FAST_DIFFERENT:
		m_led1.turnON();
		m_led2.turnOFF();
		taskDelay_ms(FAST_TIME);

		m_led1.turnOFF();
		m_led2.turnON();
		taskDelay_ms(FAST_TIME);
		break;
	}
}







