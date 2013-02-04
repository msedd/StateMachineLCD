/*
 * DecreaseAction.cpp
 *
 *  Created on: 05.07.2012
 *      Author: mse
 */

#include "DecreaseAction.h"

DecreaseAction::DecreaseAction(Dialog* dlg) {
	dialog = dlg;

}

DecreaseAction::~DecreaseAction() {
	// TODO Auto-generated destructor stub
}

void DecreaseAction::execute(){
	dialog->decrease();
}
