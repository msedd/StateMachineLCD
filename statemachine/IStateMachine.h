/*
 * IStateMachine.h
 *
 *  Created on: 05.07.2012
 *      Author: mse
 */

#ifndef ISTATEMACHINE_H_
#define ISTATEMACHINE_H_

class IStateMachine {
public:
	virtual ~IStateMachine(){};
	virtual void fireEvent(int event)=0;
};

#endif /* ISTATEMACHINE_H_ */
