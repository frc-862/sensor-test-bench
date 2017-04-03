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
  drawLine(4, 4, 155, 4, 0);
  drawLine(4, 18, 155, 18, 0);
  delay(100);
  serial.println();
  serial.print("       Hello there!");
  delay(100);
  serial.println();
  serial.println();
  
  serial.print(" Analog Zero: ~");
  delay(5); //sanity delay
  serial.print(analogRead(A0));
  serial.println();
  delay(10);
  
  serial.print(" Analog One:  ~");
  delay(5); //sanity delay
  serial.print(analogRead(A1));
  serial.println();
  delay(10);
  
  displayLCD();
  smile();
  delay(770);
}


