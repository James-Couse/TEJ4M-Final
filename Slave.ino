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
int y = 0;
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
void receiveEvent(int bytes) {
  x = Wire.read();
  Serial.println(x);
  bitStatus = x %10;
  bitNumber = (x - bitStatus) / 10;
  // Serial.println(bitNumber);
  // Serial.println(bitStatus);
  switch (bitNumber) {
      case 128: y = 8; break;
      case 64: y = 7; break;
      case 32: y = 6; break;
      case 16: y = 5; break;
      case 8: y = 4; break;
      case 4: y = 3; break;
      case 2: y = 2; break;
      case 1: y = 1; break;
  }
  // Serial.print(y);
  // Serial.print(" transposed # is "); 
  // Serial.println(y + 3);
  digitalWrite(y + 3, bitStatus);
  Serial.println("---");
}
void loop() {
}