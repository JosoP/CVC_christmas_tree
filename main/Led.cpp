/*
 * Led.cpp
 *
 *  Created on: Jan 15, 2020
 *      Author: josop
 */

#include "Led.h"

Led::Led(gpio_num_t gpio, Mode mode, bool defaultOn)
	: mode(mode)
	, gpio(gpio)
{
	gpio_pad_select_gpio(gpio);
	gpio_set_direction(gpio, GPIO_MODE_OUTPUT);

	if(defaultOn){
		turnON();
	} else {
		turnOFF();
	}
}

Led::~Led() {
	// TODO Auto-generated destructor stub
}

void Led::turnON() {
	if(this->mode == ACTIVE_LOW){
		gpio_set_level(gpio, 0);
	}else{
		gpio_set_level(gpio, 1);
	}
}

void Led::turnOFF() {
	if(this->mode == ACTIVE_LOW){
		gpio_set_level(gpio, 1);
	}else{
		gpio_set_level(gpio, 0);
	}
}

void Led::set(bool isOn) {
	if(isOn){
		turnON();
	}else{
		turnOFF();
	}
}
