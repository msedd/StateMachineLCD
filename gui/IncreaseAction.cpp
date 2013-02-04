/*
 * IncreaseAction.cpp
 *
 *  Created on: 05.07.2012
 *      Author: mse
 */

#include "IncreaseAction.h"

IncreaseAction::IncreaseAction(Dialog* dlg) {
	dialog = dlg;

}

IncreaseAction::~IncreaseAction() {
	// TODO Auto-generated destructor stub
}
void IncreaseAction::execute(){
	dialog->increase();
}

