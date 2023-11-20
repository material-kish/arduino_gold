#include <Adafruit_NeoPixel.h>
#include <Ultrasonic.h>

#define LED_pin 6
#define NUM_PIXELS 72
#define SENSOR_COUNT 3

#define MAX_BRIGHT 255
#define MIN_BRIGHT 30


Adafruit_NeoPixel pixels(NUM_PIXELS, LED_pin, NEO_GRB + NEO_KHZ800);

// Define the maximum distance threshold
const int maxDistance = 20;  // Maximum distance we want to measure

#define DELAYVAL 1


Ultrasonic ultrasonic0(2, 3);
Ultrasonic ultrasonic1(4, 5);
Ultrasonic ultrasonic2(8, 9);

void setup() {
  Serial.begin(9600);
  pixels.begin();
  pixels.show();
}

void loop() {
  // Read the sensor value
  int dist0 = ultrasonic0.read(INC);
  int dist1 = ultrasonic1.read(INC);
  int dist2 = ultrasonic2.read(INC);

  // Map the sensor reading to a brightness value (0 - 255)
  int brightness0 = map(constrain(dist0, 0, maxDistance), 0, maxDistance, MAX_BRIGHT, MIN_BRIGHT);
  int brightness1 = map(constrain(dist1, 0, maxDistance), 0, maxDistance, MAX_BRIGHT, MIN_BRIGHT);
  int brightness2 = map(constrain(dist2, 0, maxDistance), 0, maxDistance, MAX_BRIGHT, MIN_BRIGHT);

  // Update the corresponding block of LEDs
  for (int i = 0; i < 24; i++) {
    // Assuming a gold/orange hue is wanted: high red, medium green, low blue
    int redValue = brightness0;
    int greenValue = brightness0 * 0.6;  // Adjust green to 60% of the brightness
    int blueValue = brightness0 * 0.1;   // Adjust blue to 10% of the brightness

    // Now set the color to be more gold/orange rather than pure white
    pixels.setPixelColor(i, pixels.Color(redValue, greenValue, blueValue));
  }

  for (int i = 24; i < 48; i++) {
    // Assuming a gold/orange hue is wanted: high red, medium green, low blue
    int redValue = brightness1;
    int greenValue = brightness1 * 0.6;  // Adjust green to 60% of the brightness
    int blueValue = brightness1 * 0.1;   // Adjust blue to 10% of the brightness

    // Now set the color to be more gold/orange rather than pure white
    pixels.setPixelColor(i, pixels.Color(redValue, greenValue, blueValue));
  }

  for (int i = 48; i < 72; i++) {
    // Assuming a gold/orange hue is wanted: high red, medium green, low blue
    int redValue = brightness2;
    int greenValue = brightness2 * 0.6;  // Adjust green to 60% of the brightness
    int blueValue = brightness2 * 0.1;   // Adjust blue to 10% of the brightness

    // Now set the color to be more gold/orange rather than pure white
    pixels.setPixelColor(i, pixels.Color(redValue, greenValue, blueValue));
  }

  // Apply the changes to the strip
  pixels.show();
  delay(DELAYVAL);  // Small delay to avoid reading the sensors too frequently
}
