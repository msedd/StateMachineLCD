/*
 * Transition.h
 *
 *  Created on: 24.05.2012
 *      Author: mse
 */

#ifndef TRANSITION_H_
#define TRANSITION_H_

#include "State.h"
#include "IAction.h"

class State;

class Transition {
public:
	Transition(int, State*);
	Transition(int, IAction* ptrAction, State*);
	virtual ~Transition();
	void action();
	void setTarget(State*);
	State* target;
private:
	IAction* _action;
	int event;

};

#endif /* TRANSITION_H_ */
