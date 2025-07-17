const int potPin = 15; // Potentiometer connected to GPIO15
const int ledPin = 2;  // LED connected to GPIO2

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  int potValue = analogRead(potPin); // Read analog value (0–4095)
  int brightness = map(potValue, 0, 4095, 0, 1023); // Map to PWM range

  // Manual PWM simulation
  for (int i = 0; i < 50; i++) {
    digitalWrite(ledPin, HIGH);
    delayMicroseconds(brightness);  // LED on-time
    digitalWrite(ledPin, LOW);
    delayMicroseconds(1023 - brightness);  // LED off-time
  }

  Serial.println(brightness);
}
