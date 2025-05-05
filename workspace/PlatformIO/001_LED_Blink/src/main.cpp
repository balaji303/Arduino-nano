#include <Arduino.h>

// put function declarations here:
void LED_BuiltInBlink(void);

void setup() 
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
  LED_BuiltInBlink();
}

// put function definitions here:
/**
 * @brief Blinks Builtin User LED
 * 
 */
void LED_BuiltInBlink(void)
{
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
}