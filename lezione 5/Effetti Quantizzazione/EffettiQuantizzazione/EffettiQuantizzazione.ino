#define SAMPLES 128
#define SAMPLING_FREQUENCY 1000.00

unsigned int sampling_period_us;
unsigned long microseconds;

const int b0 = 2;
const int b1 = 4;
const int b2 = 7;

double L_high_res[SAMPLES];
double L_low_res[SAMPLES];
int temp;

void setup() {
  Serial.begin(115200);
  pinMode(b0, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  sampling_period_us = round(1000000*(1.0/SAMPLING_FREQUENCY));
}

void loop() {
  for (int i = 0; i < SAMPLES; i++) {
      microseconds = micros();
      L_high_res[i] = analogRead(A0);
      while(micros() < (microseconds + sampling_period_us)){};  
  }
  
  
  for (int i = 0; i < SAMPLES; i++) {
    if (L_high_res[i] == 0) {
      L_low_res[i]=0;
      digitalWrite(b2, LOW);
      digitalWrite(b1, LOW);
      digitalWrite(b0, LOW);
      }
    else if ((L_high_res[i] > 0) && (L_high_res[i] <= 128)) {
      L_low_res[i]=0;
      digitalWrite(b2, LOW);
      digitalWrite(b1, LOW);
      digitalWrite(b0, LOW);
      }
    else if ((L_high_res[i] > 128) && (L_high_res[i] <= 256)) {
      L_low_res[i]=1;
      digitalWrite(b2, LOW);
      digitalWrite(b1, LOW);
      digitalWrite(b0, HIGH);
      }
    else if ((L_high_res[i] > 256) && (L_high_res[i] <= 384)) {
      L_low_res[i]=2;
      digitalWrite(b2, LOW);
      digitalWrite(b1, HIGH);
      digitalWrite(b0, LOW);
    }
    else if ((L_high_res[i] > 384) && (L_high_res[i] <= 512)) {
      L_low_res[i]=3;
      digitalWrite(b2, LOW);
      digitalWrite(b1, HIGH);
      digitalWrite(b0, HIGH);
    }
    else if ((L_high_res[i] > 512) && (L_high_res[i] <= 640)) {
      L_low_res[i]=4;
      digitalWrite(b2, HIGH);
      digitalWrite(b1, LOW);
      digitalWrite(b0, LOW);
    }
    else if ((L_high_res[i] > 640) && (L_high_res[i] <= 768)) {
      L_low_res[i]=5;
      digitalWrite(b2, HIGH);
      digitalWrite(b1, LOW);
      digitalWrite(b0, HIGH);
    }
    else if ((L_high_res[i] > 768) && (L_high_res[i] <= 896)) {
      L_low_res[i]=6;
      digitalWrite(b2, HIGH);
      digitalWrite(b1, HIGH);
      digitalWrite(b0, LOW);
    }
    else if ((L_high_res[i] > 896) && (L_high_res[i] <= 1024)) {
      L_low_res[i]=7;
      digitalWrite(b2, HIGH);
      digitalWrite(b1, HIGH);
      digitalWrite(b0, HIGH);
    }
    }

  //for (int i = 0; i < SAMPLES; i++) {
    //Serial.print("High Res = ");
    //Serial.print((L_high_res[i]*5.00)/1023.00, 1);
    //Serial.print(", Low Res = ");
    //Serial.println((L_low_res[i]*5.00)/7.00, 1);
  //}
  //while(1);

  while(true)
  {
    for (int i = 0; i < SAMPLES; i++) {
      temp = floor(L_high_res[i]/128);
      for (int k = 0; k < 3; k++)
      {
        digitalWrite(b2, HIGH && (temp & B00000100));
        digitalWrite(b1, HIGH && (temp & B00000010));
        digitalWrite(b0, HIGH && (temp & B00000001));
      }
    }
  }
}