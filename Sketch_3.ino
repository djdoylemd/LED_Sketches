// LED Collection - Sketch 3

// Pin numbers
const int ledPin = 11;
const int analogInPin = A0;

void setup() {
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Read the analog voltage from A0
  int sensorValue = analogRead(analogInPin);

  // Map the ADC value to a frequency range 
  int frequency = map(sensorValue, 0, 1023, 10, 50);

  // Calculate the delay time for the given frequency and 50% duty cycle
  int delayTime = 1000 / (2 * frequency);

  // Toggle the LED with a 50% duty cycle
  digitalWrite(ledPin, HIGH);
  delay(delayTime);  // On time

  digitalWrite(ledPin, LOW);
  delay(delayTime);  // Off time
}
/*
This Arduino sketch toggles an LED on GPIO pin 11 at a 
rate determined by the ADC voltage at A0, where 0V 
corresponds to 10 Hertz, and 5V corresponds to 50 Hertz, 
with a 50% duty cycle. In this sketch, the map() function 
scales the ADC values (0 to 1023) to a frequency range 
between 10 and 50 Hertz. The delay time is calculated based 
on the reciprocal of twice the frequency to achieve a 
50% duty cycle.
*/