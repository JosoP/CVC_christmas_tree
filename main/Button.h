/*
 * Button.h
 *
 *  Created on: Dec 18, 2019
 *      Author: josop
 */

#pragma once

#include "driver/gpio.h"


class Button {
public:
	enum Mode {
	    INTERNAL_PULL_UP,
		INTERNAL_PULL_DOWN,
		EXTERNAL_PULL_UP,
		EXTERNAL_PULL_DOWN
	};

private:
	Mode mode;
	gpio_num_t gpio;

public:
	Button(gpio_num_t gpio, Mode mode);
	virtual ~Button();

	bool isPressed();
};

