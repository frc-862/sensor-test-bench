#include <SparkFunSerialGraphicLCD.h>//inculde the Serial Graphic LCD library
#include <SoftwareSerial.h>
//change these two pin values to whichever pins you wish to use (RX, TX)
SoftwareSerial serial2 (2, 3);
#define maxX 159 //set size for display - horizontal
#define maxY 127 //set size for display - vertical

LCD gLCD;
int analogZero = (analogRead(0));
int analogOne = (analogRead(1));
//analogZero = (analogRead(0));

String h1 = "Hello";

void setup()
{
  delay(1200);
  gLCD.setHome();
  gLCD.clearScreen();
  delay(100);
  gLCD.setX(40);
  gLCD.setY(1);
  gLCD.printStr("== Welcome ==");
  gLCD.drawLine(0, 10, 159, 10, 0);
  
  gLCD.setX(1);
  gLCD.setY(13);
  gLCD.printStr("Analog Zero: ");
  gLCD.
  gLCD.printStr("Analog One: ");
  gLCD.nextLine();
}

void loop()
{
/*
  gLCD.setX(1);
  gLCD.setY(13);
  gLCD.printStr("Analog Zero: ");
  gLCD.nextLine();
  gLCD.printStr("Analog One: ");
  gLCD.nextLine();
  delay(1000);
*/
}
/*
  void sensorRawInput()
  {
  gLCD.setX(3);
  gLCD.setY(16);
  gLCD.printNum(analogZero);
  delay(100);
  }
*/
