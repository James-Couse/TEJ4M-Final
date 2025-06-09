#include <Wire.h>

const int DIGIT_B1 = 4;
const int DIGIT_B2 = 5;
const int DIGIT_B3 = 6;
const int DIGIT_B4 = 7;
const int DIGIT_B1 = 8;
const int DIGIT_B2 = 9;
const int DIGIT_B3 = 10;
const int DIGIT_B4 = 11;

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
// Include the required Wire library for I2C<br>#include <Wire.h>
int x = 0;
void setup() {
  // Define the LED pin as Output
  pinMode (LED, OUTPUT);
  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
}
void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}
void loop() {
  switch x {
      case 1281:
            digitalWrite(DIGIT_B8, HIGH);
          break;
      case 1280:
          digitalWrite(DIGIT_B8, LOW);
          break;
      case 641:
          digitalWrite(DIGIT_B7, HIGH);
          break;
      case 640:
          digitalWrite(DIGIT_B7, LOW);
          break;
      case 321:
          digitalWrite(DIGIT_B6, HIGH);
          break;
      case 320:
          digitalWrite(DIGIT_B6, LOW);
          break;
      case 161:
          digitalWrite(DIGIT_B5, HIGH);
          break;
      case 160:
          digitalWrite(DIGIT_B5, LOW);
          break;
      case 81:
          digitalWrite(DIGIT_B4, HIGH);
          break;
      case 80:
          digitalWrite(DIGIT_B4, LOW);
          break;
      case 41:
          digitalWrite(DIGIT_B3, HIGH);
          break;
      case 40:
          digitalWrite(DIGIT_B3, LOW);
          break;
      case 21:
          digitalWrite(DIGIT_B2, HIGH);
          break;
      case 20:
          digitalWrite(DIGIT_B2, LOW);
          break;
      case 11:
          digitalWrite(DIGIT_B1, HIGH);
          break;
      case 10:
          digitalWrite(DIGIT_B1, LOW);
          break;
  //If value received is 3 blink LED for 400 ms
    }
}