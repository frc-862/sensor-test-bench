#include <Wire.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C i2cLCD(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
SoftwareSerial serial(2, 3);
void clearScreen();
void setHome();
void drawLine(byte x1, byte y1, byte x2, byte y2, byte set);
void setupLCD();
void displayLCD();
void drawCircle();
void setup() {
  serial.begin(115200);
  delay(4000);
  clearScreen();
  setHome();
  setupLCD();
}

void loop()
{
  setHome();
  drawLine(0, 4, 160, 4, 0);
  delay(100);
  serial.println();
  serial.print("       Hello there!");
  drawLine(0, 18, 160, 18, 0);
  delay(100);
  serial.println();
  serial.println();
  serial.print(" Analog Zero: ~");
  serial.print(analogRead(A0));
  serial.println();
  delay(10);
  serial.print(" Analog One: ~");
  serial.print(analogRead(A1));
  serial.println();
  displayLCD();
  delay(1000);
}


