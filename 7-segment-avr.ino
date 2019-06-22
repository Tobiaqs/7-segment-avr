#include <Wire.h>

#define SEG_A 2
#define SEG_B 3
#define SEG_C 4
#define SEG_D 5
#define SEG_E 6
#define SEG_F 7
#define SEG_G 8
#define SEG_H 9

#define DIGIT_0 10
#define DIGIT_1 11
#define DIGIT_2 12
#define DIGIT_3 13
#define DIGIT_4 14
#define DIGIT_5 15

void setup() {
  for (byte i = 2; i <= 15; i ++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  
  Wire.begin(1);
  Wire.onReceive(receiveEvent);
}

byte values[6];

byte digit = 0;

void receiveEvent(int count) {
  for (byte i = 0; i < count; i ++) {
    values[i] = Wire.read();
  }
}

void loop() {
  digitalWrite(DIGIT_0, digit == 0 ? HIGH : LOW);
  digitalWrite(DIGIT_1, digit == 1 ? HIGH : LOW);
  digitalWrite(DIGIT_2, digit == 2 ? HIGH : LOW);
  digitalWrite(DIGIT_3, digit == 3 ? HIGH : LOW);
  digitalWrite(DIGIT_4, digit == 4 ? HIGH : LOW);
  digitalWrite(DIGIT_5, digit == 5 ? HIGH : LOW);
  digitalWrite(SEG_A, (values[digit] & B1) != 0 ? HIGH : LOW);
  digitalWrite(SEG_B, (values[digit] & B10) != 0 ? HIGH : LOW);
  digitalWrite(SEG_C, (values[digit] & B100) != 0 ? HIGH : LOW);
  digitalWrite(SEG_D, (values[digit] & B1000) != 0 ? HIGH : LOW);
  digitalWrite(SEG_E, (values[digit] & B10000) != 0 ? HIGH : LOW);
  digitalWrite(SEG_F, (values[digit] & B100000) != 0 ? HIGH : LOW);
  digitalWrite(SEG_G, (values[digit] & B1000000) != 0 ? HIGH : LOW);
  digitalWrite(SEG_H, (values[digit] & B10000000) != 0 ? HIGH : LOW);

  digit ++;
  if (digit == 6) {
    digit = 0;
  }

  delayMicroseconds(2900);
}
