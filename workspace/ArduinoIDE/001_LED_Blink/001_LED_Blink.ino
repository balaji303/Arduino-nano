/**
 * @brief Main User LED Blinking
 *  
 * @author (c) 2025 by @Balaji303
 * 
 * May 03, 2025 
 * 
 */
void setup() 
{
  // put your setup code here, to run once:
  pinMode(LED_BUILTIN,OUTPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN,HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN,LOW);
  delay(1000);
}
