/*
 * State.cpp
 *
 *  Created on: 24.05.2012
 *      Author: mse
 */

#include "State.h"
#include <SerialDebug.h>

State::State(String stateName) :
		name(stateName) {
	stateful = 0;
}

void State::addTransition(int event, IAction* action, State* target) {

	Transition* transition = new Transition(event, action, target);
	transitionList.append(event, transition);

}
Transition* State::getTransition(int event) {

	Transition* ptrT = (Transition*) transitionList.getElemet(event);

	return ptrT;
}
void State::start() {
	if (stateful) {
		stateful->update();
	}
}
void State::stop() {

}

