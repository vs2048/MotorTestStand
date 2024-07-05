/*
  Counter.cpp - A counter with 2 buttons for up and down.
  Calibratable increment and decrement rate.
*/

#include "Arduino.h"
#include "Counter.h"

Counter::Counter(int upPin, int downPin, int incRate, int incTime,
					int initialCount, int stepTime, int max, int min)
{
	incButton = new Button(upPin);
	decButton = new Button(downPin);
	count = initialCount;	
	_incRate = incRate;
	_incTime = incTime;
	_stepTime = stepTime;
	_max = max;
	_min = min;
	currRate = 0;
	lastStep = millis();
}

int Counter::step()
{
	// Poll the button
	incButton->poll();
	decButton->poll();
	
	if(incButton->pressed > 0 && decButton->pressed == 0)
	{
		// If incrementing increment the rate
		currRate = 1;
		if(incButton->pressed + _incTime < millis())
		{
			currRate = _incRate;
		}
	} else if (incButton->pressed == 0 && decButton->pressed > 0)
	{
		// If decrimenting then decriment the rate
		currRate = -1;
		if(decButton->pressed + _incTime < millis())
		{
			currRate = -1 * _incRate;
		}
	} else {
		// if nothing pressed reset
		currRate = 0;
	}
	
	// Update the count based on the rate if a full timestep has passed
	if(lastStep + _stepTime < millis()) {
		lastStep = millis();
		count = count + currRate;
		if(count>_max) {
			count = _max;
		}
		if(count<_min) {
			count = _min;
		}
		Serial.println(lastStep);
	}
	return count;
}

Counter::~Counter()
{
	delete incButton;
	delete decButton;
}