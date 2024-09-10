/**
 * Onboard.c
 * Author: Luna Klatzer
 * Date: 10.09.2024
 */
#include "./LED-Display-Project.h"
#include "./Onboard.h"

#define LONG_DELAY 1000
#define SHORT_DELAY 100
#define PHASE_COUNT 4

void blink_onboard_led() {
    static unsigned long last_blink = 0;
    static bool led_state = LOW;
    static int phase = 0;

    // Determine the delay based on the current phase
    unsigned long delay_time = phase == 0 ? LONG_DELAY : SHORT_DELAY;
    if (millis() - last_blink >= delay_time) {
        last_blink = millis();
        led_state = !led_state;
        digitalWrite(LED_PIN, led_state);
        
        // Move to the next phase
        phase = (phase + 1) % PHASE_COUNT;
    }
}
