/*
 * Lights.h
 *
 *  Created on: Jan 22, 2020
 *      Author: josop
 */

#ifndef LIGHTS_H_
#define LIGHTS_H_

#include "Led.h"

class Lights {
private:
	enum Mode : char{
		SLOW_SAME,
		FAST_SAME,
		SLOW_DIFFERENT,
		FAST_DIFFERENT
	};

private:
	Led & m_led1;
	Led & m_led2;
	Mode m_mode;

public:
	Lights(Led & led1, Led & led2);
	virtual ~Lights();

	void nextMode();
	void executeModePhase();
};

#endif /* LIGHTS_H_ */
