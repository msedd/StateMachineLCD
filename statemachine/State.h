/*
 * State.h
 *
 *  Created on: 24.05.2012
 *      Author: mse
 */

#ifndef STATE_H_
#define STATE_H_

#include <WString.h>
#include "CList.h"
#include "Transition.h"
#include "IStateful.h"
#include "IAction.h"
class Transition;

class State {
public:
	State(String);
	void addTransition(int event, IAction* action, State* target);
	Transition* getTransition(int event);
	void registerStatefule(IStateful* aStatefule,
			IStateMachine* aStateMachine) {
		stateful = aStatefule;
		stateful->setStateMachine(aStateMachine);
	}
	const String getName() {
		return name;
	}
	void start();
	void stop();
private:

	CList transitionList;
	const String name;
	IStateful* stateful;
};

#endif //STATE_H_
