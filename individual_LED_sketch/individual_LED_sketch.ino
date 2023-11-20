// Define LED pins
const int ledPin1 = 2;
const int ledPin2 = 7;

void setup() {
  // Initialize the LED pins as outputs
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  // Turn the LEDs on
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);

  // Wait for 1 second (1000 milliseconds)
  delay(1000);

  // Turn the LEDs off
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);

  // Wait for 1 second
  delay(1000);
}
