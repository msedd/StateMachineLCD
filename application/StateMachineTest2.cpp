// Do not remove the include below

#include <LiquidCrystal.h>
#include <SerialDebug.h>
#include <WString.h>
#include "StateMachineTest2.h"
#include "statemachine/State.h"
#include "statemachine/StateMachine.h"
#include "IStateEvent.h"
#include "gui/Dialog.h"
#include "gui/ButtonEvent.h"
#include "statemachine/IAction.h"
#include "gui/IncreaseAction.h"
#include "gui/DecreaseAction.h"

#define DEBUG true
const String SW_VERSION = "0.1";
const String SW_NAME = "LightControl";
const String SW_AUTHOR = "Marko Seifert";

State* stSceneStoped;
State* stSceneStarted;
State* stProgamming;
State* stChaser;
StateMachine* stateMachine;

ButtonEvent* buttonEvent;

String strSceneStoped("Scene");
String strSceneStarted("Scene");
String strProgamming("Program");
String strChaser("Chaser");

int chaser[2][5] = { { 1, 0, 1, 0, 1 }, { 0, 1, 0, 1, 0 } };

LiquidCrystal* lcd;

void renderDisplay(String line1, String line2) {
	lcd->clear();
	lcd->setCursor(0, 0);
	lcd->print(line1);
	lcd->setCursor(0, 1);
	lcd->print(line2);
}

void initDebugger() {
	if (DEBUG) {
		SerialDebugger.begin(9600);
	}
	SerialDebugger.enable(NOTIFICATION);
	SerialDebugger.enable(ERROR);
	SerialDebugger.enable(WARNING);
	SerialDebugger.enable(STATUSUPDATE);
}

void initStateMachine() {

	stSceneStoped = new State("State SceneStoped");
	stSceneStarted = new State("State SceneStarted");
	stProgamming = new State("State Progamming");
	stChaser = new State("State Chaser");

	buttonEvent = new ButtonEvent(0);
	Dialog* dSceneStoped = new Dialog(lcd, buttonEvent, strSceneStoped);
	Dialog* dSceneStarted = new Dialog(lcd, buttonEvent, strSceneStarted);
	Dialog* dProgamming = new Dialog(lcd, buttonEvent, strProgamming);
	Dialog* dChaser = new Dialog(lcd, buttonEvent, strChaser);

	IAction* decreaseAction = new DecreaseAction(dSceneStoped);
	IAction* increaseAction = new IncreaseAction(dSceneStoped);

	stSceneStoped->addTransition(IStateEvent::NEXT, 0, stProgamming);
	stSceneStoped->addTransition(IStateEvent::BACK, 0, stChaser);
	stSceneStoped->addTransition(IStateEvent::START, 0, stSceneStarted);
	stSceneStoped->addTransition(IStateEvent::INCREASE, increaseAction,
			stSceneStoped);
	stSceneStoped->addTransition(IStateEvent::DECREASE, decreaseAction,
			stSceneStoped);

	stSceneStarted->addTransition(IStateEvent::STOP, 0, stSceneStoped);
	stSceneStarted->addTransition(IStateEvent::INCREASE, 0, stSceneStarted);
	stSceneStarted->addTransition(IStateEvent::DECREASE, 0, stSceneStarted);

	stProgamming->addTransition(IStateEvent::NEXT, 0, stChaser);
	stProgamming->addTransition(IStateEvent::BACK, 0, stSceneStoped);

	stChaser->addTransition(IStateEvent::NEXT, 0, stSceneStoped);
	stChaser->addTransition(IStateEvent::BACK, 0, stProgamming);

	stateMachine = new StateMachine(stSceneStoped);

	dSceneStarted->setMenuItem("STOP", IStateEvent::STOP);
	dSceneStoped->setMenuItem("START", IStateEvent::START);

	stSceneStoped->registerStatefule(dSceneStoped, stateMachine);
	stSceneStarted->registerStatefule(dSceneStarted, stateMachine);
	stChaser->registerStatefule(dChaser, stateMachine);
	stProgamming->registerStatefule(dProgamming, stateMachine);

	stateMachine->start();

}
void initLCD() {
	lcd = new LiquidCrystal(8, 9, 4, 5, 6, 7);
	lcd->clear();
	lcd->begin(16, 2);
	lcd->setCursor(0, 0);
}

void setup() {

	initDebugger();
	initLCD();
	initStateMachine();
	renderDisplay(SW_NAME + " " + SW_VERSION, char(0x01111110) + SW_AUTHOR);

	int led[] = { 2, 3, 11, 12, 13 };
	for (int i = 0; i < 5; i++) {

		pinMode(led[i], OUTPUT);
		digitalWrite(led[i], HIGH);
	}
}

// The loop function is called in an endless loop
void loop() {

	buttonEvent->readAndDispatch();

}

