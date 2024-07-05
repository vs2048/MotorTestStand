/* motor.h
 *
 * Controls a motor with PWM and reads the current from the controller on the sense pin
 */

#ifndef MOTOR_H
#define MOTOR_H

class Motor
{
	public:
		Motor(int motorPin, int sensePin, int r);
		void setSpeed(int speed);	//0-100
		void stop();
		float readCurrent();	// amps
		
	private:
		int _motorPin;
		int _sense;
		int _r;
};

#endif