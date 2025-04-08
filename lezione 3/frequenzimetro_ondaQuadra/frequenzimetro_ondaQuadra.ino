void setup() {
  Serial.begin(9600);
  pinMode(8, INPUT);
}

unsigned int Htime, Ltime;
float Ttime, freq;

void loop() {
  Htime = pulseIn(8, HIGH);
  Ltime = pulseIn(8, LOW);

  Ttime = Htime+Ltime;
  freq = 1000000/Ttime;

  Serial.println(freq);
  delay(500);

}
