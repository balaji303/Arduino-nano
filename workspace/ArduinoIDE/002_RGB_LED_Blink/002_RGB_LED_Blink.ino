/**
 * @brief RGB User LED Blinking
 * RGB LEDs are ACTIVE LOW
 *  
 * @author (c) 2025 by @Balaji303
 * 
 * May 05, 2025 
 * 
 */
void setup() 
{
  // put your setup code here, to run once:
  pinMode(LEDR,OUTPUT); //PIN024 RED LED
  pinMode(LEDG,OUTPUT); //PIN016 GREEN LED
  pinMode(LEDB,OUTPUT); //PIN006 BLUE LED
}

void loop() 
{
  // put your main code here, to run repeatedly:
  digitalWrite(LEDR,LOW);
  digitalWrite(LEDG,HIGH);
  digitalWrite(LEDB,HIGH);
  delay(1000);
  digitalWrite(LEDR,HIGH);
  digitalWrite(LEDG,HIGH);
  digitalWrite(LEDB,HIGH);
  delay(1000);

  digitalWrite(LEDR,HIGH);
  digitalWrite(LEDG,LOW);
  digitalWrite(LEDB,HIGH);
  delay(1000);
  digitalWrite(LEDR,HIGH);
  digitalWrite(LEDG,HIGH);
  digitalWrite(LEDB,HIGH);
  delay(1000);

  digitalWrite(LEDR,HIGH);
  digitalWrite(LEDG,HIGH);
  digitalWrite(LEDB,LOW);
  delay(1000);
  digitalWrite(LEDR,HIGH);
  digitalWrite(LEDG,HIGH);
  digitalWrite(LEDB,HIGH);
  delay(1000);
}
