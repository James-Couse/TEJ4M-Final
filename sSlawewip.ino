#include <Wire.h>

const int DIGIT_B1 = 12;
const int DIGIT_B2 = 9;
const int DIGIT_B3 = 6;
const int DIGIT_B4 = 3;

Serial.begin(9600);
pinMode(DIGIT_B1, OUTPUT);
pinMode(DIGIT_B2, OUTPUT);
pinMode(DIGIT_B3, OUTPUT);
pinMode(DIGIT_B4, OUTPUT);

digitalWrite(DIGIT_B1, 0);
digitalWrite(DIGIT_B2, 0);
digitalWrite(DIGIT_B3, 0);
digitalWrite(DIGIT_B4, 0);
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
  //If value received is 0 blink LED for 200 ms
  if (x == 1) {
    digitalWrite(LED, HIGH);
    delay(300);
    digitalWrite(LED, LOW);
    delay(200);
  }
  switch x {
        case 1281:
            digitalWrite(DIGIT_B1, HIGH);
            std::cout << "Excellent!" << std::endl;
            break;
  //If value received is 3 blink LED for 400 ms
  }
}