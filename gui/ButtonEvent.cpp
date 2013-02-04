/*
 * ButtonEvent.cpp
 *
 *  Created on: 19.06.2012
 *      Author: mse
 */

#include "ButtonEvent.h"
#include <SerialDebug.h>

ButtonEvent::ButtonEvent(int aAnalogInput) {
	analogInput = aAnalogInput;
	callback = 0;
	key = btnNONE;
	oldkey = btnNONE;

	SerialDebugger.debug(NOTIFICATION, "ButtonEvent::ButtonEvent",
			"Objekt erzeugt");

}

ButtonEvent::~ButtonEvent() {
	// TODO Auto-generated destructor stub
}
void ButtonEvent::readAndDispatch() {

	int adc_key_in = analogRead(analogInput);

	key = transform(adc_key_in);

	if (key != oldkey) {

		delay(50);
		adc_key_in = analogRead(0);
		key = transform(adc_key_in);

		if (key != oldkey) {
			oldkey = key;

			if (key != btnNONE && callback != 0) {
				callback->handleEvent(key);
			}
		}
	}
}

int ButtonEvent::transform(unsigned int input) {

	if (input > 1000)
		return btnNONE;
	else if (input < 50)
		return btnRIGHT;
	else if (input < 195)
		return btnUP;
	else if (input < 380)
		return btnDOWN;
	else if (input < 555)
		return btnLEFT;
	else if (input < 790)
		return btnSELECT;
	else
		return btnNONE;
}

