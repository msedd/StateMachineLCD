/*
 * Dialog.cpp
 *
 *  Created on: 23.06.2012
 *      Author: mse
 */

#include "Dialog.h"
#include "application/IStateEvent.h"
#include <SerialDebug.h>

Dialog::Dialog(LiquidCrystal* lcd, ButtonEvent* bEvent, String displayTitle) :
		menuDown("-|"), menuUP("|+"), menuLeft("<|"), menuRight("|>") {
	display = lcd;
	statemachine = 0;
	index = 1;
	buttonEvent = bEvent;

	title = displayTitle;

}
Dialog::~Dialog() {

}
/**
 * überschriebene Funktion von IStateful
 */
void Dialog::update() {
	buttonEvent->registerCallBackEventHandler(this);
	render();
}
void Dialog::setStateMachine(IStateMachine* aStatemachine) {

	statemachine = aStatemachine;
}
void Dialog::handleEvent(int bthEvent) {

	int event = 0;

	switch (bthEvent) {
	case ButtonEvent::btnRIGHT:
		event = IStateEvent::NEXT;
		break;
	case ButtonEvent::btnDOWN:
		event =  IStateEvent::DECREASE;
		break;
	case ButtonEvent::btnLEFT:
		event = IStateEvent::BACK;
		break;
	case ButtonEvent::btnUP:
		event = IStateEvent::INCREASE;
		break;
	case ButtonEvent::btnSELECT:
		event = menuEvent;
		break;
	}

	if(event){
		statemachine->fireEvent(event);
	}

}

void Dialog::render() {

	display->clear();
	display->setCursor(0, 0);
	display->print(menuLeft);
	display->setCursor(2, 0);
	display->print(title);

	display->setCursor(10, 0);
	char str[5];
	sprintf(str, "<%02d>", index);
	display->print(str);

	display->setCursor(14, 0);
	display->print(menuRight);
	display->setCursor(0, 1);
	display->print(menuDown);

	display->setCursor(5, 1);
	display->print(menuLable);
	display->setCursor(14, 1);
	display->print(menuUP);
}

void Dialog::setMenuItem(String lable, int event) {
	menuEvent = event;
	menuLable = "<" + lable + ">";
}

