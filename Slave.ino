#include <Wire.h>

const int DIGIT_B1 = 4;
const int DIGIT_B2 = 5;
const int DIGIT_B3 = 6;
const int DIGIT_B4 = 7;
const int DIGIT_B5 = 8;
const int DIGIT_B6 = 9;
const int DIGIT_B7 = 10;
const int DIGIT_B8 = 11;

int valReceived = 0;
int pinOut = 0;
int bitStatus = 0;
int bitNumber = 0;
void setup() {
	Serial.begin(9600);
	pinMode(DIGIT_B1, OUTPUT);
	pinMode(DIGIT_B2, OUTPUT);
	pinMode(DIGIT_B3, OUTPUT);
	pinMode(DIGIT_B4, OUTPUT);
	pinMode(DIGIT_B5, OUTPUT);
	pinMode(DIGIT_B6, OUTPUT);
	pinMode(DIGIT_B7, OUTPUT);
	pinMode(DIGIT_B8, OUTPUT);
	
	digitalWrite(DIGIT_B1, 0);
	digitalWrite(DIGIT_B2, 0);
	digitalWrite(DIGIT_B3, 0);
	digitalWrite(DIGIT_B4, 0);
	digitalWrite(DIGIT_B5, 0);
	digitalWrite(DIGIT_B6, 0);
	digitalWrite(DIGIT_B7, 0);
	digitalWrite(DIGIT_B8, 0);
	Wire.begin(9);
  
    Wire.onReceive(receiveEvent);
}
// tells what digit to do what based on the received data
void receiveEvent(int bytes) {
    valReceived = Wire.read();
    /* Naming convention for what output does what is weird.
    For example if the received value is "641" the final digit
    gets split off, so it becomes "64" and "1", meaning the 64s
    bit gets turned to 1/high. 80 would be 8s digit turn off.*/
    Serial.println(valReceived);
    Serial.println("---");
    bitStatus = valReceived %10; // seperates final digit
    bitNumber = (valReceived - bitStatus) / 10; // determines what digit is changed
   
    switch (bitNumber) { // selects the correct output pin for the digit
        case 128: pinOut = 8; break;
        case 64: pinOut = 7; break;
        case 32: pinOut = 6; break;
        case 16: pinOut = 5; break;
        case 8: pinOut = 4; break;
        case 4: pinOut = 3; break;
        case 2: pinOut = 2; break;
        case 1: pinOut = 1; break;
    }
    digitalWrite(pinOut + 3, bitStatus);
}
void loop() {
}