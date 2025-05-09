#include <Arduino.h>
#define MAX_LED_COUNT 3


int nanoLeds[] = { LEDR, LEDG, LEDB};

// put function declarations here:
void LED_Blink(int ledColor);

void setup() 
{
  // put your setup code here, to run once:
  for (int i=0; i < MAX_LED_COUNT; i++ )
  {
    pinMode(nanoLeds[i],OUTPUT);
  }
}

void loop() 
{
  // put your main code here, to run repeatedly:
  for(int i = 0; i< MAX_LED_COUNT; i++)
  {
    LED_Blink(nanoLeds[i]);
  }
}

// put function definitions here:
void LED_Blink(int ledColor)
{
  // 1.Turn OFF all LEDs
  for (int i=0; i< MAX_LED_COUNT; i++)
  {
    digitalWrite(nanoLeds[i],HIGH);
  }
  // 2.Turn ON the required LED
  digitalWrite(ledColor,LOW);
  delay(1000);

  // 3.Turn OFF all LEDs
  for (int i=0; i< MAX_LED_COUNT; i++)
  {
    digitalWrite(nanoLeds[i],HIGH);
  }
  delay(1000);
}