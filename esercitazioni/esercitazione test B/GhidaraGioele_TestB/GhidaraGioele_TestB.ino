#define SAMPLING_FREQUENCY 1000    // Frequenza di campionamento
#define SAMPLES 64                // Numero di campioni

unsigned int sampling_period_us;
unsigned long microseconds;
double media, varianza;

double v[SAMPLES];               // Campioni acquisiti
double rs[SAMPLES];              // Running sum
double fd[SAMPLES];              // First Difference
double dft[SAMPLES / 2];         // DFT segnale
double dft_rs[SAMPLES / 2];      // DFT running sum
double dft_fd[SAMPLES / 2];      // DFT first differece

void setup() {
  Serial.begin(115200);
  sampling_period_us = 1000000 / SAMPLING_FREQUENCY;
}

void loop() {
  // Acquisizione dei campioni
  for (int i = 0; i < SAMPLES; i++) {
    microseconds = micros();
    v[i] = analogRead(A0);
    while (micros() < (microseconds + sampling_period_us)) {}
  }

  // Calcoli
  media = mean(v, SAMPLES);
  varianza = variance(v, SAMPLES, media);
  running_sum(v, rs, SAMPLES);
  first_difference(v, fd, SAMPLES);
  calc_dft(v, dft, SAMPLES);
  calc_dft(rs, dft_rs, SAMPLES);
  calc_dft(fd, dft_fd, SAMPLES);

  // Visualizzazione DFT
  for (int i = 0; i < SAMPLES / 2; i++) {
    Serial.print(dft[i]);      // DFT del segnale originale
    Serial.print("\t");
    Serial.print(dft_rs[i]);   // DFT della running sum
    Serial.print("\t");
    Serial.println(dft_fd[i]); // DFT della first difference
  }

  // Visualizzazione media e varianza
  Serial.print("Media: ");
  Serial.println(media, 2);
  Serial.print("Varianza: ");
  Serial.println(varianza, 2);

  delay(1000);
}

// funzioni

// media
double mean(double *v, int N) {
  double sum = 0.0;
  for (int i = 0; i < N; i++) {
    sum += v[i];
  }
  return sum / N;
}

// varianza
double variance(double *v, int N, double media) {
  double var = 0.0;
  for (int i = 0; i < N; i++) {
    var += pow(v[i] - media, 2);
  }
  return var / (N - 1);
}

// running sum
void running_sum(double *src, double *dest, int N) {
  if (N > 0) {
    dest[0] = src[0];
    for (int i = 1; i < N; i++) {
      dest[i] = dest[i - 1] + src[i];
    }
  }
}

// first difference
void first_difference(double *src, double *dest, int N) {
  dest[0] = 0;
  for (int i = 1; i < N; i++) {
    dest[i] = src[i] - src[i - 1];
  }
}

// dft
void calc_dft(double *array_campioni, double *array_modulo, int N) {
  for (int k = 0; k < (N / 2); k++) {
    double Re = 0.0;
    double Im = 0.0;
    for (int i = 0; i < N; i++) {
      Re += array_campioni[i] * cos(2.0 * PI * k * i / N);
      Im -= array_campioni[i] * sin(2.0 * PI * k * i / N);
    }
    array_modulo[k] = sqrt(Re * Re + Im * Im); // modulo
  }
}
