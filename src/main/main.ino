#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>
SoftwareSerial serial(2, 3); //RX, TX
/*
Due to the fact that the MCU running the display is slower than the one we are
programming, we need to include lots of delays for them to catch up to eachother,
so they don't trip over commands and we don't end up with a corrupted image on
the display.
-Nolan Adams
This code is released under an MIT License
*/


void setup()
{
  serial.begin(115200); //Start serial port at 115200 baud
  delay(3500); //wait for display microcontroller to boot
  clearScreen(); //make sure display is free of errors

  delay(50); //Stability delay

  setHome(); //sets X and Y back to 0

  delay(50); //stability delay

  drawGridlines(); //Main box around labels and data output text


  setX(25); //set location for title text
  setY(8); // ^
  delay(50); //stability delay
  serial.print("Sensor Test Bench"); //title at the top of the screen
  delay(50);
  setX(25);
  setY(23);
  serial.print("Input");
  setX(100);
  serial.print("Value");


  delay(200); //replaces smile for stability's sake
  printXColumn();
  delay(100); //delay before loop starts
}

void loop()
{
  setHome();
  printYColumn();
  delay(1000);

  //drawBox(76, 33, 154, 80, 0); //to show where the erased area is

  //delay(100);
  setHome();
  eraseBlock(76, 33, 154, 80);
  //clear the area where the values are displayed to remove residual digits if value gains or loses a digit

}
