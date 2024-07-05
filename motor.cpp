/* motor.cpp
 *
 * Controls a motor with PWM and reads the current on the sense pin
 */

#include "motor.h"
#include "arduino.h"

// Constructor initializes pins
Motor::Motor(int motorPin, int sensePin, int r)
{
	_motorPin = motorPin;
	_sense = sensePin;
	_r = r;
	
	pinMode(motorPin, OUTPUT);
	pinMode(sensePin, INPUT);
}

// setSpeed sets the pwm pulse width based on a 0-100 command
void Motor::setSpeed(int speed)
{
	int pwm = map(speed, 0, 100, 0, 255);
	analogWrite(_motorPin, pwm);
}

// Stops the motor
void Motor::stop()
{
	analogWrite(_motorPin, 0);
}


// Reads the current from the motor controller
float Motor::readCurrent()
{
	float volts = (float)analogRead(_sense) * 0.0049;
	return volts/(float)_r;
}