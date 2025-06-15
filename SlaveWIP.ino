#include <Wire.h>

const int DIGIT_B1 = 4;
const int DIGIT_B2 = 5;
const int DIGIT_B3 = 6;
const int DIGIT_B4 = 7;
const int DIGIT_B5 = 8;
const int DIGIT_B6 = 9;
const int DIGIT_B7 = 10;
const int DIGIT_B8 = 11;

int x = 0;
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
void receiveEvent(int bytes) {
  x = Wire.read();
  Serial.println(x);
  Serial.println("---");
  switch (x) {
      case 1281:
          digitalWrite(DIGIT_B8, 1);
    	  x = 0;
      case 1280:
          digitalWrite(DIGIT_B8, 0);
      	  x = 0;
      case 641:
          digitalWrite(DIGIT_B7, 1);
    	  x = 0;
      case 640:
          digitalWrite(DIGIT_B7, 0);
    	  x = 0;
      case 321:
          digitalWrite(DIGIT_B6, 1);
      	  x = 0;
      case 320:
          digitalWrite(DIGIT_B6, 0);
    	  x = 0;
      case 161:
          digitalWrite(DIGIT_B5, 1);
      	  x = 0;
      case 160:
          digitalWrite(DIGIT_B5, 0);
    	  x = 0;
      case 81:
          digitalWrite(DIGIT_B4, 1);
      	  x = 0;
      case 80:
          digitalWrite(DIGIT_B4, 0);
    	  x = 0;
      case 41:
          digitalWrite(DIGIT_B3, 1);
    	  x = 0;
      case 40:
          digitalWrite(DIGIT_B3, 0);
    	  x = 0;
      case 21:
          digitalWrite(DIGIT_B2, 1);
    	  x = 0;
      case 20:
          digitalWrite(DIGIT_B2, 0);
    	  x = 0;
      case 11:
          digitalWrite(DIGIT_B1, 1);
    	  x = 0;
      case 10:
          digitalWrite(DIGIT_B1, 0);
    	  x = 0;
    }
}
void loop() {
}