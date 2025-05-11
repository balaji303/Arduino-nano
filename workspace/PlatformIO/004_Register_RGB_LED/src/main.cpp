/**
 * @file main.cpp
 * @author @balaji303 (https://github.com/balaji303)
 * @brief RGB LED Blinker using nRF52840 direct register access
 * @version 1
 * @date 10-05-2025
 * 
 * Copyright (c) 2025 @balaji303
 */

#include <Arduino.h>
#include <nrf52840.h>

// --- Pin Definitions for onboard RGB LED (Active LOW logic) ---
#define RGB_LED_R     (1 << 24)  // Red LED connected to P0.24
#define RGB_LED_G     (1 << 16)  // Green LED connected to P0.16
#define RGB_LED_B     (1 << 6)   // Blue LED connected to P0.06

#define MAX_LED_COUNT (3)        // Total number of LEDs (R, G, B)

// --- Array of LED pin bitmasks for easy looping ---
int nano_RGBLeds[] = { RGB_LED_R, RGB_LED_G, RGB_LED_B };

// --- Function Prototypes ---
void off_AllLed(void);
void register_RGBLedBlink(int LedColor);

void setup()
{
  // Configure RGB LED pins as OUTPUT
  for (int i = 0; i < MAX_LED_COUNT; i++)
  {
    NRF_P0->DIRSET |= nano_RGBLeds[i];  // Set pin as output
  }

  // Initially turn off all LEDs (Active LOW = HIGH to turn off)
  off_AllLed();
}

void loop() 
{
  // Loop through each LED and blink it once
  for (int i = 0; i < MAX_LED_COUNT; i++)
  {
    register_RGBLedBlink(nano_RGBLeds[i]);
  }
}

/**
 * @brief Turn OFF all RGB LEDs
 * 
 * Since the RGB LEDs are active LOW, setting the pin HIGH turns the LED OFF.
 * This function writes to OUTSET to set all pins HIGH (turn off all LEDs).
 */
void off_AllLed(void)
{
  for (int i = 0; i < MAX_LED_COUNT; i++)
  {
    NRF_P0->OUTSET = nano_RGBLeds[i];  // Set pin HIGH = turn off LED
  }
}

/**
 * @brief Blink a specific RGB LED
 * 
 * Steps:
 * 1. Turn OFF all LEDs to ensure only one LED is ON at a time
 * 2. Toggle the selected LED to turn it ON (Active LOW)
 * 3. Delay for 1 second
 * 4. Turn OFF all LEDs again
 * 5. Delay for 1 second before next blink
 * 
 * @param LedColor Bitmask of the LED to blink (RGB_LED_R, G, or B)
 */
void register_RGBLedBlink(int LedColor)
{
  off_AllLed();              // Step 1: Turn OFF all LEDs
  NRF_P0->OUT ^= LedColor;   // Step 2: Toggle to turn ON target LED (Active LOW)
  delay(1000);               // Step 3: Wait

  off_AllLed();              // Step 4: Turn OFF all LEDs
  delay(1000);               // Step 5: Wait
}
