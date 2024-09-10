/**
 * Setup functionality for the project.
 * Author: Luna Klatzer
 * Date: 10.09.2024
 */
#ifndef LED_DISPLAY_PROJECT_H_SETUP_H
#define LED_DISPLAY_PROJECT_H_SETUP_H

#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif

// On-board LED pin
#define LED_PIN 13

// Setup macro which prints the start of the setup process
#define SETUP_BEGIN Serial.begin(9600); Serial.println("-- Setup --");

// Setup macro which prints the end of the setup process
#define SETUP_END Serial.println("Setup complete!");

#ifdef __cplusplus
}
#endif

#endif//LED_DISPLAY_PROJECT_H_SETUP_H
