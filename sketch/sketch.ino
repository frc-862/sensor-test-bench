#include <Wire.h>

//These lines are for LCD config - uncomment these lines and comment the LiquidCrystal_I2C ones for regular LCD wiring configs
//#include <LCD.h>
//LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//These are the LiquidCrystal_I2C config lines for i2c lcd displays (4 wires: VCC | GND | SDA | SCL )
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  Serial.begin(9600); //start serial communication: 9600 BAUD
  lcd.begin(20, 4, LCD_5x8DOTS); //start LCD, 20 characters, 4 lines, 5x8dot matrix
  lcd.setCursor(0, 0); //set cursor at char0 line0
  lcd.print(" Sensor Readings r2 "); //display heading
  lcd.setCursor(0, 1); //cursor at char1 line0
  lcd.print("  Analog / Digital  ");
  lcd.setCursor(0, 2);
  lcd.print("A0   A1   D2   D3");
  lcd.setCursor(0, 3);
  lcd.print("                    "); //clear reading line
}

void loop() {
  lcd.setCursor(0, 3); //set cursor at readings line
  lcd.print("                    "); //clear reading line
  {
    lcd.setCursor(0, 3);
    lcd.print(analogRead(A0)); //display A0 analog data
  }
  {
    lcd.setCursor(5, 3);
    lcd.print(analogRead(A1)); //display A1 analog data
  }
  {
    lcd.setCursor(10, 3);
    lcd.print(digitalRead(2)); //display D2 digital data
  }
  {
    lcd.setCursor(15, 3);
    lcd.print(digitalRead(3)); //display D3 digital data
  }
  delay(250);
}
