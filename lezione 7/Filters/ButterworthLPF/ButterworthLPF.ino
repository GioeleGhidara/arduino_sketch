float xn1 = 0;
float yn1 = 0;
int k = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Test signal
  float t= micros()/1.0e6;
  float xn = sin(2*PI*2*t) + 0.2* sin(2*PI*50*t);
  
  float yn = 0.969*yn1 + 0.0155*xn + 0.0155*xn1; // Butterworth First Order LPF

  delay(1);
  xn1 = xn;
  yn1 = yn;

  if (k % 3 == 0) {
    // Output
    Serial.print(2*xn);
    Serial.print(" ");
    Serial.println(yn);
  }

  k = k+1;

}
