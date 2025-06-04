// Created on: Jan 2024
// Created by: James Couse
// Created for: This is the code for a 2-bit adder

const int DIGIT_A1 = 13;
const int DIGIT_B1 = 12;
const int DIGIT_A2 = 10;
const int DIGIT_B2 = 9;
const int DIGIT_A3 = 7;
const int DIGIT_B3 = 6;
const int DIGIT_A4 = 4;
const int DIGIT_B4 = 3;
const int ADD_SUB = 2;

// either adding (0) or subtracting (1)
int addsub = 0;

// comment
int counter(int addsub) {
  digitalWrite(ADD_SUB, addsub);
  Serial.print(addsub);
  if (addsub < 2) {
    Serial.print(addsub);
      for (int twosA = 0; twosA <= 1; ++twosA) { // 2A
        digitalWrite(DIGIT_A2, twosA);
        for (int twosB = 0; twosB <= 1; ++twosB) { // 2B
          digitalWrite(DIGIT_B2, twosB);
          for (int onesA = 0; onesA <= 1; ++onesA) { // 1A
            digitalWrite(DIGIT_A1, onesA);
            for (int onesB = 0; onesB <= 1; ++onesB) { // 1B
              digitalWrite(DIGIT_B1, onesB);
              delay(500);
            }
          }
        }
      }
    Serial.print(addsub);
    return addsub * counter(addsub + 1);
  }

  else {
        return addsub;
  }
}

// comment
void setup() {
    // setup serial output
  Serial.begin(9600);
  // set pin mode to output
  pinMode(DIGIT_A1, OUTPUT);
  pinMode(DIGIT_B1, OUTPUT);
  pinMode(DIGIT_A2, OUTPUT);
  pinMode(DIGIT_B2, OUTPUT);
  pinMode(DIGIT_A3, OUTPUT);
  pinMode(DIGIT_B3, OUTPUT);
  pinMode(DIGIT_A4, OUTPUT);
  pinMode(DIGIT_B4, OUTPUT);
  pinMode(ADD_SUB, OUTPUT);
  
  // set all pins to "0)
  digitalWrite(DIGIT_A1, 0); //LOW and HIGH just reference 0 & 1
  digitalWrite(DIGIT_B1, 0);
  digitalWrite(DIGIT_A2, 0);
  digitalWrite(DIGIT_B2, 0);
  digitalWrite(DIGIT_A3, 0);
  digitalWrite(DIGIT_B3, 0);
  digitalWrite(DIGIT_A4, 0);
  digitalWrite(DIGIT_B4, 0);
  digitalWrite(ADD_SUB, 0);
  
  // loop over the inputs
  Serial.print("Starting ... \n\n");
  Serial.println(addsub);
  digitalWrite(ADD_SUB, addsub);
  int addsub = counter(addsub);
}


void loop() {
  // Done
  Serial.print("\nDone. \n");
  delay(100000000); // Wait for 10000 millisecond(s)
}