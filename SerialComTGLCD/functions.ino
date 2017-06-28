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

void smile() {
  drawCircle(132, 100, 20, 0); //large circle
  drawCircle(122, 95, 2, 0); //left eye
  drawCircle(142, 95, 2, 0); //right eye
  drawLine(122, 107, 127, 110, 0); //left smile line
  drawLine(127, 110, 137, 110, 0); //center line
  drawLine(137, 110, 142, 107, 0); //right line
}
void drawGridlines() {
  delay(10);
  drawLine(4, 4, 155, 4, 0); //title bar top
  drawLine(4, 18, 155, 18, 0); //title bar bottom
  delay(5);
  drawLine(4, 22, 155, 22, 0); //box top
  drawLine(4, 22, 4, 100, 0); //box left
  delay(5);
  drawLine(4, 100, 112, 100, 0); //box bottom
  drawLine(153, 100, 155, 100, 0); //box bottom after smile
  delay(5);
  drawLine(155, 22, 155, 100, 0); //box right
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
//  delay(10);
  setX(10);
  setY(27);
  serial.print("Analog 0");
  serial.println();
  serial.print("Analog 1");
  serial.println();
  serial.print("Analog 2");
//  delay(10);
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

