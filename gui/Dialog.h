/*
 * Dialog.h
 *
 *  Created on: 23.06.2012
 *      Author: mse
 */

#ifndef DIALOG_H_
#define DIALOG_H_

#include <WString.h>
#include <LiquidCrystal.h>
#include "statemachine/IStateMachine.h"
#include "ButtonEvent.h"
#include "statemachine/IStateful.h"
#include "ICallbackEventHandler.h"

class Dialog: public IStateful, public ICallbackEventHandler {
public:
	Dialog(LiquidCrystal* lcd, ButtonEvent*, String displayTitle);
	virtual ~Dialog();

	void render();
	void setMenuItem(String lable, int event);

	virtual void update();
	virtual void setStateMachine(IStateMachine*);

	void increase() {
		index++;
	}
	void decrease() {
		index--;
	}
	virtual void handleEvent(int btnEvent);

private:
	const String menuLeft;
	const String menuRight;
	const String menuUP;
	const String menuDown;

	int menuEvent;
	int index;

	String menuLable;
	String title;

	LiquidCrystal* display;
	IStateMachine * statemachine;
	ButtonEvent* buttonEvent;
	int transformButtonToStateEvent(int key);
};

#endif /* DIALOG_H_ */
