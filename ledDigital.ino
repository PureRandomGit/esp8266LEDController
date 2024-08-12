#include <FastLED.h>

#define NUM_LEDS 66
#define LED_PIN 4 //Pin D2
#define INPUT_PIN 5 //Pin D5

CRGB leds[NUM_LEDS];

void setup() {
    // Initialize the FastLED library with the specified pin
    FastLED.addLeds<NEOPIXEL, LED_PIN>(leds, NUM_LEDS);

    // Set the input pin mode
    pinMode(INPUT_PIN, INPUT);
}

void loop() {
    // Read the state of the input pin
    int inputState = digitalRead(INPUT_PIN);

    // Set color based on the input state
    CRGB color;
    if (inputState == HIGH) {
        color = CRGB::Green;  // Set to green if input is HIGH
    } else {
        color = CRGB::Orange; // Default to orange
    }

    // Apply the color to all LEDs
    for(int i = 0; i < NUM_LEDS; i++) {
        leds[i] = color;
    }

    // Update the LEDs
    FastLED.show();

    // Small delay to avoid rapid toggling
    delay(30);
}