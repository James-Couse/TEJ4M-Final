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