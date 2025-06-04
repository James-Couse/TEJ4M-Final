#include <Wire.h>
int LED = 13;
// Include the required Wire library for I2C<br>#include 
void setup() {
  // Start the I2C Bus as Master
  Wire.begin(); 
  pinMode (LED, OUTPUT);
}
void loop() {
  Wire.beginTransmission(9); // transmit to device #9
  Wire.write(1);              // sends x 
  digitalWrite(LED, HIGH);
    delay(300);
    digitalWrite(LED, LOW);
    delay(200);
  Wire.endTransmission();    // stop transmitting
}