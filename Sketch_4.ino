// LED Collection - Sketch 4

// Pin numbers
const int ledPin = 11;
const int analogInPin = A0;

// Variables for managing time
unsigned long previousToggleMillis = 0;
unsigned long previousPrintMillis = 0;
int frequency = 0;

void setup() {
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the analog voltage from A0
  int sensorValue = analogRead(analogInPin);

  // Map the ADC value to a frequency range (adjust the range according to your requirements)
  frequency = map(sensorValue, 0, 1023, 10, 50);

  // Calculate the period for the given frequency and 50% duty cycle
  int period = 1000 / (2 * frequency);

  // Get the current time
  unsigned long currentMillis = millis();

  // Check if it's time to toggle the LED
  if (currentMillis - previousToggleMillis >= period) {
    // Save the current time
    previousToggleMillis = currentMillis;

    // Toggle the LED with a 50% duty cycle
    digitalWrite(ledPin, !digitalRead(ledPin));
  }

  // Check if it's time to print the frequency
  if (currentMillis - previousPrintMillis >= 1000) {
    // Save the current time
    previousPrintMillis = currentMillis;

    // Print the frequency to the Serial Monitor
    Serial.print("Frequency: ");
    Serial.print(frequency);
    Serial.println(" Hz");
  }
}
/*
To take into account the time needed to print the frequency to the Serial Monitor, 
we use a separate variable to track the last time the frequency was printed. 
In this sketch, two separate variables (previousToggleMillis and previousPrintMillis) 
are used to track the last time the LED was toggled and the last time the frequency 
was printed, respectively.
*/
