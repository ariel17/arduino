#include "MQ7.h"
#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

// const int LED_PIN = 8;

const int C0_A_PIN = 0;
MQ7 mq7(C0_A_PIN, 5.0);

void setup() {
  // pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("C0 LEVEL:");
  
  int ppm = mq7.getPPM();
  char level[10];
  sprintf(level, "%d", ppm);
  
  lcd.setCursor(5, 1);
  lcd.print(level);

  delay(500);
}
