/*
 * StringTools.c - a collection of string helping functions
 */

#include <math.h>

void StringTools_int2str(int target, char* buff, char len){
	//Parse out the individual characters
	int targetParce = target;
	for(int i = 1; i<=len; i++) {
		buff[len-i] = targetParce % 10;
		targetParce = targetParce / 10;
	}
	// convert to characters
	char leading0 = 1;
	for(int i = 0; i<len; i++) {
		if(buff[i] == 0 && leading0 == 1) {
			if (i == len - 1) {
				buff[i] = '0';
			}
			else {
				buff[i] = ' ';
			}
		}
		else {
			leading0 = 0;
			buff[i] = '0' + buff[i];
		}
	}
	buff[len] = 0;
}

void StringTools_float2str(float target, char* buff, char len, char numDec) {
	int lenInteger = len - numDec - 1;

	//Seperate the decimal
	int integer = (int)target;
	int dec = (target - (float)integer) * pow(10, numDec);

	//Populate the integer
	for (int i = 1; i <= lenInteger; i++) {
		buff[lenInteger - i] = integer % 10;
		integer = integer / 10;
	}
	
	buff[lenInteger] = '.';

	//Populate the decimal
	for (int i = 1; i <= numDec; i++) {
		buff[len - i] = dec % 10;
		dec = dec / 10;
	}

	//Convert to characters
	char leading0 = 1;
	for (int i = 0; i<len; i++) {
		if (buff[i] == 0 && leading0 == 1) {
			buff[i] = ' ';
		}
		else if (buff[i] == '.') {
			if (leading0 == 1) {
				if (i > 0) {
					buff[i - 1] = '0';
				}
				leading0 = 0;
			}
		}
		else {
			leading0 = 0;
			buff[i] = '0' + buff[i];
		}
	}
	buff[len] = 0;
}