#include <Wire.h>
int LED = 13;
int addsub = 0;

int counter(int addsub) {
    const int DIGIT_A1 = 4;
	const int DIGIT_A2 = 5;
	const int DIGIT_A3 = 6;
	const int DIGIT_A4 = 7;
	const int DIGIT_A5 = 8;
	const int DIGIT_A6 = 9;
	const int DIGIT_A7 = 10;
	const int DIGIT_A8 = 11;

	const int ADD_SUB = 2;
  
    
  	Serial.begin(9600);
 	pinMode(DIGIT_A1, OUTPUT);
	pinMode(DIGIT_A2, OUTPUT);
	pinMode(DIGIT_A3, OUTPUT);
	pinMode(DIGIT_A4, OUTPUT);
	pinMode(DIGIT_A5, OUTPUT);
	pinMode(DIGIT_A6, OUTPUT);
	pinMode(DIGIT_A7, OUTPUT);
	pinMode(DIGIT_A8, OUTPUT);
	pinMode(ADD_SUB, OUTPUT);
  
	// set all pins to "0)
	digitalWrite(DIGIT_A1, 0); //LOW and HIGH just reference 0 & 1
	digitalWrite(DIGIT_A2, 0);
  	digitalWrite(DIGIT_A3, 0);
  	digitalWrite(DIGIT_A4, 0);
	digitalWrite(DIGIT_A5, 0); //LOW and HIGH just reference 0 & 1
	digitalWrite(DIGIT_A6, 0);
  	digitalWrite(DIGIT_A7, 0);
  	digitalWrite(DIGIT_A8, 0);
  	digitalWrite(ADD_SUB, addsub);

	// either adding (0) or subtracting (1)
  	if (addsub < 2) {
    	Serial.println(addsub);
     	for (int EightA = 0; EightA <= 1; ++EightA) { // 2A
       		digitalWrite(DIGIT_A8, EightA);
       		for (int EightB = 0; EightB <= 1; ++EightB) { // 2B
         		if (EightB == 0) {
                    Wire.beginTransmission(9);
					Wire.write(1280);
                    Wire.endTransmission();
        
				}
				if (EightB == 1) {
                    Wire.beginTransmission(9);
					Wire.write(1281);
                    Wire.endTransmission();
				}
          		for (int SevenA = 0; SevenA <= 1; ++SevenA) { // 1A
            		digitalWrite(DIGIT_A7, SevenA);
            		for (int SevenB = 0; SevenB <= 1; ++SevenB) { // 1B
              			if (SevenB == 0) {
                            Wire.beginTransmission(9);
							Wire.write(640);
                            Wire.endTransmission();
						}
						if (SevenB == 1) {
                            Wire.beginTransmission(9);
							Wire.write(641);
                            Wire.endTransmission();
						}
						for (int SixA = 0; SixA <= 1; ++SixA) { // 2A
       						digitalWrite(DIGIT_A6, SixA);
       						for (int SixB = 0; SixB <= 1; ++SixB) { // 2B
         						if (SixB == 0) {
                                    Wire.beginTransmission(9);
									Wire.write(320);
                                    Wire.endTransmission();
								}
								if (SixB == 1) {
                                    Wire.beginTransmission(9);
									Wire.write(321);
                                    Wire.endTransmission();
								}
          						for (int FiveA = 0; FiveA <= 1; ++FiveA) { // 1A
            						digitalWrite(DIGIT_A5, FiveA);
            						for (int FiveB = 0; FiveB <= 1; ++FiveB) { // 1B
              							if (FiveB == 0) {
                                            Wire.beginTransmission(9);
											Wire.write(160);
                                            Wire.endTransmission();
										}
										if (FiveB == 1) {
                                            Wire.beginTransmission(9);
											Wire.write(161);
                                            Wire.endTransmission();
										}
										for (int FourA = 0; FourA <= 1; ++FourA) { // 2A
       										digitalWrite(DIGIT_A4, FourA);
       										for (int FourB = 0; FourB <= 1; ++FourB) { // 2B
         										if (FourB == 0) {
                                                    Wire.beginTransmission(9);
													Wire.write(80);
                                                    Wire.endTransmission();
												}
												if (FourB == 1) {
                                                    Wire.beginTransmission(9);
													Wire.write(81);
                                                    Wire.endTransmission();
												}
												for (int ThreeA = 0; ThreeA <= 1; ++ThreeA) { // 1A
													digitalWrite(DIGIT_A3, ThreeA);
													for (int ThreeB = 0; ThreeB <= 1; ++ThreeB) { // 1B
														if (ThreeB == 0) {
                                                            Wire.beginTransmission(9);
															Wire.write(40);
                                                            Wire.endTransmission();
														}
														if (ThreeB == 1) {
                                                            Wire.beginTransmission(9);
															Wire.write(41);
                                                            Wire.endTransmission();
														}
														for (int TwoA = 0; TwoA <= 1; ++TwoA) { // 2A
															digitalWrite(DIGIT_A2, TwoA);
															for (int TwoB = 0; TwoB <= 1; ++TwoB) { // 2B
																if (TwoB == 0) {
                                                                    Wire.beginTransmission(9);
																	Wire.write(20);
                                                                    Wire.endTransmission();
																}
																if (TwoB == 1) {
                                                                    Wire.beginTransmission(9);
																	Wire.write(21);
                                                                    Wire.endTransmission();
																}
																for (int OneA = 0; OneA <= 1; ++OneA) { // 1A
																	digitalWrite(DIGIT_A1, OneA);
																	for (int OneB = 0; OneB <= 1; ++OneB) { // 1B
																		if (OneB == 0) {
                                                                            Wire.beginTransmission(9);
																			Wire.write(10);
                                                                            Wire.endTransmission();
                                                                            Serial.println("sending 10");
																		}  
																		if (OneB == 1) {
                                                                            Wire.beginTransmission(9);
																			Wire.write(11);
                                                                            Wire.endTransmission();
                                                                            Serial.println("sending 11");
																		}
              														delay(2000);
																	}
																}
															}
														}
													}
												}
											}
										}
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
  Wire.beginTransmission(9);
  counter(addsub);
  Wire.endTransmission();
}
void loop() {
  Serial.print("\nDone. \n");
  delay(100000000); // Wait for 10000 millisecond(s)
}