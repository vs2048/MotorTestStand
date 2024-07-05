/*
 *  MotorTestStand2.ino
 *
 * A test stand for a electric motor
 * A Motor object controls the motor's operation
 * ON and OFF buttons control power to the motor
 * A Counter object reads buttons to increase and decrease speed
 * Speed and powers are writen to the LCD
 */

#include "LiquidCrystal.h"
#include "StringTools.h"
#include "Counter.h"
#include "motor.h"

// Initialize the pins
#define ON 1
#define OFF 0
#define LED 4

Counter speed(3, 2, 10, 500, 0, 100, 100, 0);
LiquidCrystal lcd(9, 10, 7, 8, 12, 13);
Motor motor(11, A0, 2);

// Strings
char pwmBuff[4];
char ampBuff[5];

char onOff;

// Initialization functions
void setup() {
	lcd.begin(16,2);
	onOff = 0;
	
	pinMode(ON, INPUT_PULLUP);
	pinMode(OFF, INPUT_PULLUP);
	pinMode(LED, OUTPUT);
	digitalWrite(LED, 0);
	motor.stop();
	
	lcd.clear();
	lcd.write("Motor Controller");
	lcd.setCursor(0,1);
	lcd.write("    Standby     ");
}

void loop() {
	//The main loop is governed by the switch
	switch(onOff)
	{
		case 0:
			// if OFF check to see if the on button is pressed
			if(digitalRead(ON) == 0) {
				// If ON is requested reset the LED.
				// The actual command to start will be handled in the next loop()
				onOff = 1;
				lcd.clear();
				digitalWrite(LED,1);
				speed.count = 0;
				lcd.setCursor(0,1);
				lcd.write("     Active     ");
			}
			break;
		case 1:
			// If ON check for a stop request
			if(digitalRead(OFF) == 0) {
				motor.stop();
				lcd.clear();
				lcd.write("Motor Controller");
				lcd.setCursor(0,1);
				lcd.write("    Standby     ");
				digitalWrite(LED, 0);
				onOff = 0;
			}
			else {
				// If no off request run the motor and get the speed and torque
				speed.step();
				motor.setSpeed(speed.count);
				// Use StringTools to convert numbers to strings
				StringTools_int2str(speed.count, pwmBuff, 3);
				StringTools_float2str(motor.readCurrent(), ampBuff, 4, 2);
				// Write to the LCD
				lcd.setCursor(0,0);
				lcd.write("PWM (%)      ");
				lcd.write(pwmBuff);
			}
	}
}