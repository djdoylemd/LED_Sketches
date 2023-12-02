// LED Series - Sketch 2

// Pin number for the LED
const int ledPin = 13;

// Time variables
const int cycleTime = 1000; // 1 Hertz frequency (1000 milliseconds)
const int onTime = 100;     // 10% duty cycle on time (100 milliseconds)

void setup() {
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Turn on the LED
  digitalWrite(ledPin, HIGH);
  delay(onTime);

  // Turn off the LED
  digitalWrite(ledPin, LOW);
  delay(cycleTime - onTime);
}
