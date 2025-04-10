#define SAMPLES 128
#define SAMPLING_FREQUENCY 1000

unsigned int sampling_period_us;
unsigned long microseconds;

double v[SAMPLES];

void setup() {
  Serial.begin(115200);
  sampling_period_us = round(1000000*(1.0/SAMPLING_FREQUENCY));
}

void loop() {
  for (int i = 0; i < SAMPLES; i++) {
    microseconds = micros();
    v[i] = analogRead(A0);
    while(micros() < (microseconds + sampling_period_us)) {};
  }

  for (int i = 0;i < SAMPLES; i++)  {
    Serial.println(v[i],1);
  }
  while(1);
}
