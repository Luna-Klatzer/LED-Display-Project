/**
 * Onboard.h
 * Author: Luna Klatzer
 * Date: 10.09.2024
 */
#ifndef LED_DISPLAY_PROJECT_H_ONBOARD_H
#define LED_DISPLAY_PROJECT_H_ONBOARD_H

#include <Arduino.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Non-blocking function to blink the onboard LED.
 */
void blink_onboard_led();

#ifdef __cplusplus
}
#endif

#endif//LED_DISPLAY_PROJECT_H_ONBOARD_H
