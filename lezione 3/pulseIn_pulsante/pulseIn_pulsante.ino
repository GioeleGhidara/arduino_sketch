#define BUTTON_PIN 12

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  unsigned long duration = pulseIn(BUTTON_PIN, HIGH); // pulseln ( ) è in microsecondi [um]
  Serial.println(duration);
}
