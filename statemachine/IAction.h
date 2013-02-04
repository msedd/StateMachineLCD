/*
 * IAction.h
 *
 *  Created on: 05.07.2012
 *      Author: mse
 */

#ifndef IACTION_H_
#define IACTION_H_

class IAction {
public:
	virtual ~IAction(){};
	virtual void execute()=0;
};

#endif /* IACTION_H_ */
