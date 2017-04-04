#include <Wire.h>
#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C i2cLCD(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
SoftwareSerial serial(2, 3);



void setup() {
  serial.begin(115200);
  setupLCD();
  delay(4000);
  clearScreen();
  

  delay(10);
  setHome();
  delay(10);

  drawGridlines();
  setX(45);
  setY(8);
  delay(10);
  serial.print("Hello There!");
  delay(10);
}

void loop()
{
  eraseBlock(66, 23, 154, 99);
  delay(250);
  setHome();
  //delay(100);

  delay(100);


  setHome();
  xColumn();
  yColumn();

  delay(500);

  delay(10);
  displayLCD();
  //smile();
  delay(510);
}


