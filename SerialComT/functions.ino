#include <Arduino.h>

void clearScreen()
{
  serial.write(0x7C);
  serial.write((byte)0);
}
void setHome()
{
  serial.write(0x7C);
  serial.write(0x18);
  serial.write((byte)0);//set x back to 0
  serial.write(0x7C);
  serial.write(0x19);
  serial.write((byte)0);//set y back to 0
}
void drawLine(byte x1, byte y1, byte x2, byte y2, byte set)
{
  //draws a line from two given points. You can set and reset just as the pixel function.
  serial.write(0x7C);
  serial.write(0x0C);//CTRL l
  serial.write(x1);
  serial.write(y1);
  serial.write(x2);
  serial.write(y2);
  serial.write(0x01);
  delay(10);
}
void setupLCD() {
  i2cLCD.begin(20, 4, LCD_5x8DOTS); //start LCD, 20 characters, 4 lines, 5x8dot matrix
  i2cLCD.setCursor(0, 0); //set cursor at char0 line0
  i2cLCD.print(" Sensor Readings r2 "); //display heading
  i2cLCD.setCursor(0, 1); //cursor at char1 line0
  i2cLCD.print("  Analog / Digital  ");
  i2cLCD.setCursor(0, 2);
  i2cLCD.print("A0   A1   D2   D3");
  i2cLCD.setCursor(0, 3);
}
void displayLCD() {
  i2cLCD.setCursor(0, 3); //set cursor at readings line
  i2cLCD.print("                    "); //clear reading line
  i2cLCD.setCursor(0, 3);
  i2cLCD.print(analogRead(A0)); //display A0 analog data
  i2cLCD.setCursor(5, 3);
  i2cLCD.print(analogRead(A1)); //display A1 analog data
  i2cLCD.setCursor(10, 3);
  i2cLCD.print(digitalRead(2)); //display D2 digital data
  i2cLCD.setCursor(15, 3);
  i2cLCD.print(digitalRead(3)); //display D3 digital data
}
void drawCircle(byte x, byte y, byte rad, byte set) {
//draws a circle from a point x,y with a radius of rad. 
//Circles can be drawn off-grid, but only those pixels that fall within the 
//display boundaries will be written.
  serial.write(0x7C);
  serial.write(0x03);//CTRL c 
  serial.write(x);
  serial.write(y);
  serial.write(rad);
  serial.write(0x01);
  delay(10);
  
}
