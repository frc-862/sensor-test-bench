#include <Arduino.h>

#include <Wire.h>
#include <SoftwareSerial.h>
SoftwareSerial serial(2, 3);



void setup() {
  serial.begin(115200);
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
  smile();
  xColumn();
  delay(10);
}

void loop()
{
  //drawBox(66,23,154,99, 1);
  eraseBlock(66, 23, 154, 70);
  delay(250);
  setHome();
  delay(100);

  delay(100);


  setHome();

  yColumn();

  delay(500);

  //delay(10);


  delay(510);
}
