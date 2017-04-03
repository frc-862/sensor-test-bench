#include <Wire.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C i2cLCD(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
SoftwareSerial serial(2, 3);
void clearScreen();
void setHome();
void drawLine();
void setupLCD();
void displayLCD();
void drawCircle();
void smile();
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
  drawLine(0, 18, 160, 18, 0);
  delay(100);
  serial.println();
  serial.print("       Hello there!");
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
  smile();
  delay(1000);
}
void smile() {
  drawCircle(125, 100, 20, 0); //large circle
  drawCircle(115, 95, 2, 0); //left eye
  drawCircle(135, 95, 2, 0); //right eye
  drawLine(115, 107, 120, 110, 0); //left smile line
  drawLine(120, 110, 130, 110, 0); //center line
  drawLine(130, 110, 135, 107, 0); //right line
}

