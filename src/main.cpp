#include <Arduino.h>
#include <BleMouse.h>
#include <cmath>

BleMouse bleMouse("Lab Rescue Mouse", "Szitake Inc.");
double xDegrees = 0.0;

void setup()
{
  Serial.begin(115200);
  Serial.println("Starting BLE work!");
  bleMouse.begin();
}

void loop()
{
  const int r = 2;

  if(bleMouse.isConnected()) 
  {
    int x = round(r*sin(xDegrees*3.14159/180));
    int y = round(r*cos(xDegrees*3.14159/180*2));

    bleMouse.move(x,y);

    if(++xDegrees >= 360)
    {
      xDegrees = 0;
      Serial.println("Left Click!");
      bleMouse.click(MOUSE_LEFT);
    }
    else if(xDegrees == 180)
    {
      Serial.println("Right Click!");
      bleMouse.click(MOUSE_RIGHT);
    }
  }

  delay(10);
}