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
}
void loop() {
  switch (x) {
      case 1281:
          digitalWrite(DIGIT_B8, HIGH);
      case 1280:
          digitalWrite(DIGIT_B8, LOW);
      case 641:
          digitalWrite(DIGIT_B7, HIGH);
      case 640:
          digitalWrite(DIGIT_B7, LOW);
      case 321:
          digitalWrite(DIGIT_B6, HIGH);
      case 320:
          digitalWrite(DIGIT_B6, LOW);
      case 161:
          digitalWrite(DIGIT_B5, HIGH);
      case 160:
          digitalWrite(DIGIT_B5, LOW);
      case 81:
          digitalWrite(DIGIT_B4, HIGH);
      case 80:
          digitalWrite(DIGIT_B4, LOW);
      case 41:
          digitalWrite(DIGIT_B3, HIGH);
      case 40:
          digitalWrite(DIGIT_B3, LOW);
      case 21:
          digitalWrite(DIGIT_B2, HIGH);
      case 20:
          digitalWrite(DIGIT_B2, LOW);
      case 11:
          digitalWrite(DIGIT_B1, HIGH);
      case 10:
          digitalWrite(DIGIT_B1, LOW);
    }
}