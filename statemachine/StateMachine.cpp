/*
 * StateMachine.cpp
 *
 *  Created on: 30.05.2012
 *      Author: mse
 */

#include "StateMachine.h"
#include <SerialDebug.h>

StateMachine::StateMachine(State* startState) {
	current = startState;
}

StateMachine::~StateMachine() {
}

void StateMachine::calculate(int event) {

	char buffer[50];

	sprintf(buffer, "Event: %d", event);
	SerialDebugger.debug(STATUSUPDATE, "StateMachine::calculate", buffer);

	Transition* ptrT = current->getTransition(event);

	if (ptrT != 0) {
		char name_current[20];
		char name_next[20];

		current->getName().toCharArray(name_current, 20, 0);
		ptrT->target->getName().toCharArray(name_next, 20, 0);

		sprintf(buffer, "Zustandsübergang: %s -> %s", name_current, name_next);

		SerialDebugger.debug(STATUSUPDATE, "StateMachine::calculate", buffer);

		current->stop();
		ptrT->action();
		current = ptrT->target;
		current->start();

	} else {
		SerialDebugger.debug(NOTIFICATION, "StateMachine::calculate",
				"keine Transition");
	}

}
void StateMachine::start(){
	if(current)
		current->start();
}

