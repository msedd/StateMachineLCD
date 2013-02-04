/*
 * DecreaseAction.h
 *
 *  Created on: 05.07.2012
 *      Author: mse
 */

#ifndef DECREASEACTION_H_
#define DECREASEACTION_H_

#include "statemachine/IAction.h"
#include "Dialog.h"
class DecreaseAction: public IAction {
public:
	DecreaseAction(Dialog* dlg);
	virtual ~DecreaseAction();
	virtual void execute();

private:
	Dialog* dialog;

};

#endif /* DECREASEACTION_H_ */
