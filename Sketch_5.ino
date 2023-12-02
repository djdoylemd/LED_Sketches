// LED Series - Sketch 5

// Pin numbers
const int ledPin = 11;
const int potPin = A0;

void setup() {
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);

  // Start serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the potentiometer
  int potValue = analogRead(potPin);

  // Map the potentiometer value to PWM range (0 to 255)
  int pwmValue = map(potValue, 0, 1023, 0, 255);

  // Set the LED intensity using PWM
  analogWrite(ledPin, pwmValue);

  // Print the potentiometer value and corresponding 
  // PWM value and Duty to Serial Monitor
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  Serial.print(",   PWM Value: ");
  Serial.print(pwmValue);
  Serial.print(",   Duty Cycle (Fraction): ");
  Serial.println(pwmValue/255.0);

  // Add a small delay for stability
  delay(10);
}
/*
In this sketch, the analog value read from the potentiometer (connected to A0) 
is mapped to the PWM range (0 to 255). The analogWrite() function is then used 
to set the LED intensity based on the calculated PWM value. Be sure to connect 
the potentiometer appropriately, ensuring that it has three pins (connect the 
outer pins to power and ground, and the middle pin to A0).
*/