// LED Series - Sketch 1

// Pin number for the LED
const int ledPin = 13;

// Time variables
unsigned long previousMillis = 0;
const long interval = 500; // 1 Hertz frequency means 500 milliseconds per LED state

// LED state
int ledState = LOW;

void setup() {
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Get the current time
  unsigned long currentMillis = millis();

  // Check if the specified interval has passed
  if (currentMillis - previousMillis >= interval) {
    // Save the current time
    previousMillis = currentMillis;

    // Toggle the LED state
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    // Apply the LED state to the pin
    digitalWrite(ledPin, ledState);
  }
}
/*
This sketch uses the millis() function to keep track of time and 
toggles the LED state every 500 milliseconds (1 Hertz cycle frequency). 
The duty cycle is 50% since the LED is turned on and off alternately. 
The LED is connected to GPIO pin 13; you can adjust the ledPin 
variable if your LED is connected to a different pin.
*/