/*
 * IncreaseAction.h
 *
 *  Created on: 05.07.2012
 *      Author: mse
 */

#ifndef INCREASEACTION_H_
#define INCREASEACTION_H_

#include "statemachine/IAction.h"
#include "Dialog.h"

class IncreaseAction: public IAction {
public:
	IncreaseAction(Dialog* dlg);
	virtual ~IncreaseAction();
	virtual void execute();
private:
	Dialog* dialog;
};

#endif /* INCREASEACTION_H_ */
