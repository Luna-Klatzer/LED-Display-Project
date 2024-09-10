/**
 * First program for programming the Elegoo UNO R3
 * Author: Luna Klatzer
 * Date: 10.09.2024
 */
#include <LED-Display-Project.h>

/**
 * Setup function for the microcontroller. 
 * 
 * This sets up the microcontroller and then runs the main loop.
 */
void setup() {
  SETUP_BEGIN;
  pinMode(LED_PIN, OUTPUT);
  SETUP_END;
}

/**
 * Main loop for the microcontroller.
 * 
 * This is where the main functionality of the microcontroller is implemented.
 */
void loop() {
  blink_onboard_led();
}
