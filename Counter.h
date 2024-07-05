/*
  Counter.h - A counter with 2 buttons for up and down.
  Calibratable increment and decrement rate if a button is held.

  Call step to run the counter.
*/

#ifndef COUNTER_h
#define COUNTER_h

#include "Button.h"
#include "Arduino.h"

class Counter
{
	public:
		Counter(int upPin, int downPin, int incRate, int incTime,
				int initialCount, int stepTime, int max, int min);
		int step();
		int count;
		~Counter();
	private:
		Button *incButton, *decButton;
		int _incRate;
		int _incTime;
		int _stepTime;
		int _max, _min;
		int currRate;
		unsigned long lastStep;
};

#endif