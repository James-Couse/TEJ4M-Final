#include <Wire.h>
int LED = 13;
int addsub = 0;
// Include the required Wire library for I2C<br>#include 

int counter(int addsub) {
    const int DIGIT_A1 = 13;
	const int DIGIT_A2 = 10;
	const int DIGIT_A3 = 7;
	const int DIGIT_A4 = 4;

	const int ADD_SUB = 2;
  
    
  	Serial.begin(9600);
 	pinMode(DIGIT_A1, OUTPUT);
	pinMode(DIGIT_A2, OUTPUT);
	pinMode(DIGIT_A3, OUTPUT);
	pinMode(DIGIT_A4, OUTPUT);
	pinMode(ADD_SUB, OUTPUT);
  
	// set all pins to "0)
	digitalWrite(DIGIT_A1, 0); //LOW and HIGH just reference 0 & 1
	digitalWrite(DIGIT_A2, 0);
  	digitalWrite(DIGIT_A3, 0);
  	digitalWrite(DIGIT_A4, 0);
  	digitalWrite(ADD_SUB, addsub);

	// either adding (0) or subtracting (1)
	Wire.beginTransmission(9)
  	if (addsub < 2) {
    	Serial.println(addsub);
     	for (int EightA = 0; twosA <= 1; ++twosA) { // 2A
       		digitalWrite(DIGIT_A2, twosA);
       		for (int EightB = 0; twosB <= 1; ++twosB) { // 2B
         		if (EightB == 0) {
					Wire.write(128);
				}
				if (EightB == 1) {
					Wire.write(129);
				}
          		for (int SevenA = 0; onesA <= 1; ++onesA) { // 1A
            		digitalWrite(DIGIT_A1, onesA);
            		for (int SevenB = 0; onesB <= 1; ++onesB) { // 1B
              			if (SevenB == 0) {
							Wire.write(64);
						}
						if (SevenB == 1) {
							Wire.write(65);
						}
						for (int SixA = 0; twosA <= 1; ++twosA) { // 2A
       						digitalWrite(DIGIT_A2, twosA);
       						for (int SixB = 0; twosB <= 1; ++twosB) { // 2B
         						digitalWrite(DIGIT_B2, twosB);
          						for (int FiveA = 0; onesA <= 1; ++onesA) { // 1A
            						digitalWrite(DIGIT_A1, onesA);
            						for (int FiveB = 0; onesB <= 1; ++onesB) { // 1B
              							digitalWrite(DIGIT_B1, onesB);
              						delay(500);
            						}
          						}
        					}
      					}
            		}
          		}
        	}
      	}
    Serial.println(addsub);
    return addsub * counter(addsub + 1);
  	}

  	else {
        return addsub;
  	}
}

void setup() {
  // Start the I2C Bus as Master
  Wire.begin(); 
  pinMode (LED, OUTPUT);

  // setup serial output
  Serial.print("Starting ... \n\n");
  counter(addsub);
}
void loop() {
  Serial.print("\nDone. \n");
  delay(100000000); // Wait for 10000 millisecond(s)
}

// comment