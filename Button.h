/*
 * Button.h - library to track what is happening with a button
 *
 * Debounces the switch and sets the status in the pressed and released variables.
 * call poll() in the main loop
 */

#ifndef BUTTON_h
#define BUTTON_h

class Button
{
	public:
		Button(int pin);
		bool poll();
		unsigned long pressed;
		unsigned long released;
	private:
		int _pin;
		static const int debounceTime = 1;
};

#endif