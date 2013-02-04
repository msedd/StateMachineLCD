/*
 * IStatefule.h
 *
 *  Created on: 05.07.2012
 *      Author: mse
 */

#ifndef ISTATEFUL_H_
#define ISTATEFUL_H_

#include "IStateMachine.h"

class IStateful {
public:
	virtual ~IStateful() {
	}
	;
	virtual void update()=0;
	virtual void setStateMachine(IStateMachine*)=0;

};

#endif /* ISTATEFUL_H_ */
