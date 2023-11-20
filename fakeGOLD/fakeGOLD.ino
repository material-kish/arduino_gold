#include <Adafruit_NeoPixel.h>
#include <Ultrasonic.h>

#define LED_pin 6
#define NUM_PIXELS 72
#define SENSOR_COUNT 3

#define MAX_BRIGHT 255
#define MIN_BRIGHT 30


Adafruit_NeoPixel pixels(NUM_PIXELS, LED_pin, NEO_GRB + NEO_KHZ800);

// Define the maximum distance threshold
const int maxDistance = 70;  // Maximum distance we want to measure

#define DELAYVAL 4


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

  // colors
  int red0 = 0;
  int green0 = 0;
  int blue0 = 0;

  int red1 = 0;
  int green1 = 0;
  int blue1 = 0;

  int red2 = 0;
  int green2 = 0;
  int blue2 = 0;


  // Update the corresponding block of LEDs
  for (int i = 0; i < 24; i++) {
    if(dist0 < 6)
    {
      red0 = 255;
    }
    else if(dist0 < 12)
    {
      green0 = 255;
    }
    else
    {
      blue0 = 255;
    }
    pixels.setPixelColor(i, pixels.Color(red0, green0, blue0));
  }

  for (int i = 24; i < 48; i++) {
    if(dist1 < 6)
    {
      red1 = 255;
    }
    else if(dist1 < 12)
    {
      green1 = 255;
    }
    else
    {
      blue1 = 255;
    }
    pixels.setPixelColor(i, pixels.Color(red1, green1, blue1));
  }

  for (int i = 48; i < 72; i++) {
    if(dist2 < 6)
    {
      red2 = 255;
    }
    else if(dist2 < 12)
    {
      green2 = 255;
    }
    else
    {
      blue2 = 255;
    }
    pixels.setPixelColor(i, pixels.Color(red2, green2, blue2));
  }

  // Apply the changes to the strip
  pixels.show();
  delay(DELAYVAL);  // Small delay to avoid reading the sensors too frequently
}
