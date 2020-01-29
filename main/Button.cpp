/*
 * Button.cpp
 *
 *  Created on: Dec 18, 2019
 *      Author: josop
 */

#include "Button.h"



Button::Button(gpio_num_t gpio, Mode mode)
	: mode(mode)
	, gpio(gpio)
{
	printf("Zacina constructor\n");
	gpio_pad_select_gpio(this->gpio);
	gpio_set_direction(this->gpio, GPIO_MODE_INPUT);

	gpio_pull_mode_t pull_mode;

	switch(this->mode){
	case INTERNAL_PULL_UP:
		pull_mode = GPIO_PULLUP_ONLY;
		break;
	case INTERNAL_PULL_DOWN:
		pull_mode = GPIO_PULLDOWN_ONLY;
		break;
	case EXTERNAL_PULL_UP:
	case EXTERNAL_PULL_DOWN:
		pull_mode = GPIO_FLOATING;
		break;
	default:
		pull_mode = GPIO_PULLUP_ONLY;
	}

	gpio_set_pull_mode(gpio, pull_mode);


}

Button::~Button() {
}

bool Button::isPressed() {

	switch(this->mode){
		case INTERNAL_PULL_UP:
		case EXTERNAL_PULL_UP:
			return (gpio_get_level(gpio) == 0);
		case INTERNAL_PULL_DOWN:
		case EXTERNAL_PULL_DOWN:
			return (gpio_get_level(gpio) == 1);
		default:
			return false;
	}
}
