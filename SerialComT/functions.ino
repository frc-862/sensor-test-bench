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
