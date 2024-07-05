/*
 * Button.cpp - library to track what is happening with a button
 *
 * Debounces the switch and sets the status in the pressed and released variables
 */

#include "Arduino.h"
#include "Button.h"

// Constructor assignes the pin
Button::Button(int pin)
{
	_pin = pin;
	pinMode(_pin, INPUT);
	digitalWrite(_pin, 1);
	pressed = 0;
	released = 0;
}

//
bool Button::poll()
{
	char currentState = digitalRead(_pin);
	if(pressed == 0 && currentState == 0 && millis() - debounceTime > released) {
		pressed = millis();
		released = 0;
		return true;
	}
	if(released == 0 && currentState == 1 && millis() - debounceTime > pressed) {
		released = millis();
		pressed = 0;
		return true;
	}
	return false;
}