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
  delay(5);
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
void drawBox(byte x1, byte y1, byte x2, byte y2, byte set)
{
  //draws a box from two given points. You can set and reset just as the pixel function. 
  serial.write(0x7C);
  serial.write(0x0F);//CTRL o 
  serial.write(x1);
  serial.write(y1);
  serial.write(x2);
  serial.write(y2);
  serial.write(0x01);
  delay(10);
  
}
void eraseBlock(byte x1, byte y1, byte x2, byte y2) {
  //This is just like the draw box command, except the contents of the box are erased to the background color
  serial.write(0x7C);
  serial.write(0x05);//CTRL e 
  serial.write(x1);
  serial.write(y1);
  serial.write(x2);
  serial.write(y2);
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
void smile() {
  drawCircle(125, 100, 20, 0); //large circle
  drawCircle(115, 95, 2, 0); //left eye
  drawCircle(135, 95, 2, 0); //right eye
  drawLine(115, 107, 120, 110, 0); //left smile line
  drawLine(120, 110, 130, 110, 0); //center line
  drawLine(130, 110, 135, 107, 0); //right line
}
void drawGridlines() {
  delay(10);
  drawLine(4, 4, 155, 4, 0); //title bar top
  drawLine(4, 18, 155, 18, 0); //title bar bottom
  drawBox(4, 22, 155, 100, 0); //box border
  drawLine(65, 22, 65, 100, 0); //box divider
  delay(10);
}
void setY(byte posY)//0-63 or 0-127 pixels
{
  //Set the y position 
  serial.write(0x7C);
  serial.write(0x19);//CTRL y
  serial.write(posY);
  
}
void setX(byte posX) //0-127 or 0-159 pixels
{
  //Set the X position 
  serial.write(0x7C);
  serial.write(0x18);//CTRL x
  serial.write(posX);
}
void xColumn() {
  delay(10);
  setX(10);
  setY(27);
  serial.print("Analog 0");
  serial.println();
  serial.print("Analog 1");
  serial.println();
  serial.print("Analog 2");
  delay(10);
}
void yColumn() {
  delay(10);
  setX(83);
  setY(27);
  serial.print(analogRead(A0));
  serial.println();
  serial.print(analogRead(A1));
  serial.println();
  serial.print(analogRead(A2));
  delay(10);
}

