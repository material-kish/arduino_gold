#include <Adafruit_NeoPixel.h>
#include <Ultrasonic.h>

#define LED_pin 6
#define NUM_PIXELS 72
#define SENSOR_COUNT 3


Adafruit_NeoPixel pixels(NUM_PIXELS, LED_pin, NEO_GRB + NEO_KHZ800);

// Define the maximum distance threshold
const int maxDistance = 250;  // Maximum distance we want to measure

#define DELAYVAL 400


Ultrasonic ultrasonic1(2, 3);
Ultrasonic ultrasonic2(4, 5);
Ultrasonic ultrasonic3(8, 9);

Ultrasonic sensor_array[] = { ultrasonic1, ultrasonic2, ultrasonic3 };

void setup() {
  Serial.begin(9600);
  pixels.begin();
  pixels.show();
}

void loop() {
  for (int i = 0; i < SENSOR_COUNT; i++) {
    // Read the sensor value
    int sensorValue = sensor_array[i].read(INC);

    // Map the sensor reading to a brightness value (0 - 255)
    int brightness = map(constrain(sensorValue, 0, maxDistance), 0, maxDistance, 255, 0);



    Serial.print("Sensor ");
    Serial.print(i);
    Serial.print(":\n");
    Serial.print("BRIGHTNESS: ");
    Serial.println(brightness);

    // Update the corresponding block of LEDs
    for (int j = i * 24; j < (i + 1) * 24; j++) {
      // Assuming a gold/orange hue is wanted: high red, medium green, low blue
      int redValue = brightness;
      int greenValue = brightness * 0.6;  // Adjust green to 60% of the brightness
      int blueValue = brightness * 0.1;   // Adjust blue to 10% of the brightness

      // Now set the color to be more gold/orange rather than pure white
      pixels.setPixelColor(j, pixels.Color(redValue, greenValue, blueValue));

      Serial.print("red: ");
      Serial.println(redValue);
      Serial.print("green: ");
      Serial.println(greenValue);
      Serial.print("blue: ");
      Serial.println(blueValue);
    }
  }

  // Apply the changes to the strip
  pixels.show();
  delay(50);  // Small delay to avoid reading the sensors too frequently
}
