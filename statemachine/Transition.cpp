/*
 * Transition.cpp
 *
 *  Created on: 24.05.2012
 *      Author: mse
 */

#include "Transition.h"

Transition::Transition(int aEent, State* targetState) {

	event = aEent;
	target = targetState;
}
Transition::Transition(int aEent, IAction* ptrAction, State* targetState) {
	_action = ptrAction;
	event = aEent;
	target = targetState;
}

Transition::~Transition() {
	// TODO Auto-generated destructor stub
}

void Transition::action() {
	if (_action) {
		_action->execute();
	}
}

void Transition::setTarget(State* aState) {

	target = aState;
}

