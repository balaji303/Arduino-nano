/**
 * @file main.cpp
 * @author @balaji303 (https://github.com/balaji303)
 * @brief RGB Led Blink in Arduino Nano
 * @version 1
 * @date 10-05-2025
 * 
 * Copyright (c) 2025 @balaji303
 * 
 */
#include <Arduino.h>
#define MAX_LED_COUNT 3

/**
 * @brief Array of RGB LEDs present in Nano
 * 
 */
int nanoLeds[] = { LEDR, LEDG, LEDB};

// Declaration
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

/**
 * @brief Blinks the required LED passed with a delay of 1sec
 * 
 * @param ledColor 
 */
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