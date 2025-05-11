/**
 * @file main.cpp
 * @author @balaji303
 * @brief Blinks an LED connected to pin P0.13 using nRF52840 direct register access
 * @version 1.0
 * @date 10-05-2025
 * 
 * Copyright (c) 2025 @balaji303
 */

#include <Arduino.h>
#include <nrf52840.h>

// --- Function Declaration ---
void register_LEDBlink(void);

void setup()
{
  /**
   * Configure GPIO P0.13 as OUTPUT
   * DIRSET register sets direction bits to OUTPUT
   * Equivalent to: pinMode(13, OUTPUT);
   */
  NRF_P0->DIRSET |= (1 << 13);
}

void loop() 
{
  // Call function to toggle LED state
  register_LEDBlink();
}

/**
 * @brief Toggles the state of LED on P0.13
 * 
 * Uses XOR on OUT register to flip the output state of P0.13
 * - If it was HIGH, it becomes LOW (LED ON if active LOW)
 * - If it was LOW, it becomes HIGH (LED OFF)
 * Equivalent to: digitalWrite(13, !digitalRead(13));
 */
void register_LEDBlink(void)
{
  NRF_P0->OUT ^= (1 << 13);  // Toggle pin P0.13 state
  delay(1000);               // Wait 1 second
}
