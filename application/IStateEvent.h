/*
 * Stateevent.h
 *
 *  Created on: 05.07.2012
 *      Author: mse
 */

#ifndef STATEEVENT_H_
#define STATEEVENT_H_

class IStateEvent {
public:

	virtual ~IStateEvent();
	enum {
		NEXT = 1,
		BACK = 2,
		SELECT = 3,
		INCREASE = 4,
		DECREASE = 5,
		START = 6,
		STOP = 7,
		TIMER = 8,
		EDIT = 9,
	};
};

#endif /* STATEEVENT_H_ */
