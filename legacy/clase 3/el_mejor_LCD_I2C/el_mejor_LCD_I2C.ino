#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR 0x27
#define I2C_ADDR_2 0x3F

LiquidCrystal_I2C lcd(I2C_ADDR,2, 1, 0, 4, 5, 6, 7);
LiquidCrystal_I2C lcd2(I2C_ADDR_2,2, 1, 0, 4, 5, 6, 7);
void setup()
   {
       lcd.begin (16,2);    // Inicializar el display con 16 caraceres 2 lineas
       lcd.setBacklightPin(3,POSITIVE);
       lcd.setBacklight(HIGH);

       lcd.home ();                   // go home
       lcd.print("      EANT");
       lcd.setCursor ( 0, 1 );        // go to the 2nd line
       lcd.print("      2017");
        //lcd2
       lcd2.begin (16,2);    // Inicializar el display con 16 caraceres 2 lineas
       lcd2.setBacklightPin(3,POSITIVE);
       lcd2.setBacklight(HIGH);

       lcd2.home ();                   // go home
       lcd2.print("      EANT");
       lcd2.setCursor ( 0, 1 );        // go to the 2nd line
       lcd2.print("      2017");
  
       
   }
void loop() 
   {}
