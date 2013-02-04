/*
 * StateMachine.h
 *
 *  Created on: 30.05.2012
 *      Author: mse
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#include "State.h"
#include "IStateMachine.h"

class StateMachine: public IStateMachine {
public:
	StateMachine(State*);
	virtual ~StateMachine();
	State* getCurrent() {
		return current;
	}
	virtual void fireEvent(int event) {
		calculate(event);
	}

	void calculate(int event);
	void start();

private:
	State * current;
};

#endif /* STATEMACHINE_H_ */
