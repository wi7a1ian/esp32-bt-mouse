#include <Arduino.h>
#include <BleMouse.h>
#include <cmath>

BleMouse bleMouse("Lab Rescue Mouse", "Szitake Inc.");
double xDegrees = 0.0;

void setup()
{
  // https://stackoverflow.com/a/75576025
  Serial.begin(115200, SERIAL_8N1);
  Serial.end();
  Serial.begin(115200, SERIAL_8N1);
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
  else
  {
    Serial.println("Not connected.");
    delay(1000);
  }

  delay(10);
}