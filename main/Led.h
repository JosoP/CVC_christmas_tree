/*
 * Led.h
 *
 *  Created on: Jan 15, 2020
 *      Author: josop
 */

#pragma once

#include "driver/gpio.h"

class Led {
public:
	enum Mode {
		ACTIVE_LOW,
		ACTIVE_HIGH
	};

private:
	Mode mode;
	gpio_num_t gpio;

public:
	Led(gpio_num_t gpio, Mode mode, bool defaultOn = false);
	Led(const Led & other) = delete;
	virtual ~Led();

	void turnON();
	void turnOFF();
	void set(bool isOn);
};

