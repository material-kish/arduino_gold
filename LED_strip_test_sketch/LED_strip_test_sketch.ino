// #include <Adafruit_NeoPixel.h>

// // Define the pin where the data line is connected
// #define LED_PIN     6

// // Define the number of LEDs in the strip
// #define LED_COUNT  20  // Set this to 20 for the first 20 pixels

// // Create an instance of the Adafruit_NeoPixel class called "strip"
// Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// void setup() {
//   // Initialize the NeoPixel strip
//   strip.begin();

//   // Set all pixels in the strip to 'off'
//   strip.show();
// }

// void loop() {
//   // Light up the first 20 LEDs in red color
//   for(int i = 0; i < LED_COUNT; i++) { // Loop over each pixel
//     strip.setPixelColor(i, strip.Color(255, 0, 0)); // Set pixel 'i' to red
//   }

//   // This sends the updated pixel colors to the hardware.
//   strip.show();

//   // Pause for a moment
//   delay(500);

//   // Turn off the first 20 LEDs
//   for(int i = 0; i < LED_COUNT; i++) { // Loop over each pixel
//     strip.setPixelColor(i, strip.Color(0, 0, 0)); // Turn off pixel 'i'
//   }

//   // Update the strip to turn off the pixels
//   strip.show();

//   // Pause for a moment
//   delay(500);
// }



// Simple NeoPixel test.  Lights just a few pixels at a time so a
// 1m strip can safely be powered from Arduino 5V pin.  Arduino
// may nonetheless hiccup when LEDs are first connected and not
// accept code.  So upload code first, unplug USB, connect pixels
// to GND FIRST, then +5V and digital pin 6, then re-plug USB.
// A working strip will show a few pixels moving down the line,
// cycling between red, green and blue.  If you get no response,
// might be connected to wrong end of strip (the end wires, if
// any, are no indication -- look instead for the data direction
// arrows printed on the strip).

#include <Adafruit_NeoPixel.h>

#define PIN      2
#define N_LEDS 144

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
}

void loop() {
  chase(strip.Color(255, 0, 0)); // Red
  chase(strip.Color(0, 255, 0)); // Green
  chase(strip.Color(0, 0, 255)); // Blue
}

static void chase(uint32_t c) {
  for(uint16_t i=0; i<strip.numPixels()+4; i++) {
      strip.setPixelColor(i  , c); // Draw new pixel
      strip.setPixelColor(i-4, 0); // Erase pixel a few steps back
      strip.show();
      delay(25);
  }
}