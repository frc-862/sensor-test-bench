#include <SoftwareSerial.h>
SoftwareSerial serial(2, 3);
void clearScreen();
void setHome();
void drawLine(byte x1, byte y1, byte x2, byte y2, byte set);
void setup() {
  serial.begin(115200);
  delay(4000);
  clearScreen();
  setHome();
}

void loop()
{
  setHome();
  drawLine(0, 4, 160, 4, 0);
  delay(100);
  serial.println();
  serial.println(" Hello there!");
  delay(100);
  serial.println();
  serial.print(" ");
  serial.print(analogRead(A0));
  serial.println();
  delay(1000);

}


