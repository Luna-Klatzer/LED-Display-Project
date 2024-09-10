/**
 * First program for programming the Elegoo UNO R3
 * Author: Luna Klatzer
 * Date: 10.09.2024
 */
#include "LED-Display-Project.h"
#include <Arduino.h>

/**
 * Setup function for the microcontroller. 
 * 
 * This sets up the microcontroller and then runs the main loop.
 */
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello World!");
}

/**
 * Main loop for the microcontroller.
 * 
 * This is where the main functionality of the microcontroller is implemented.
 */
void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);
  Serial.println("Hello World!");
}
