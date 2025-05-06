#define FS 500
#define N1 80
#define N2 100
#define PI 3.14159265

void generaSegnale(float x[], int N, float f1, float f2, float A1, float A2);
void DFT(float x[], float Xabs[], int N);

float x1[N1], Xabs1[N1];
float x2[N2], Xabs2[N2];

void setup() {
  Serial.begin(115200);

  float f1 = 50.0;
  float f2 = 120.0;
  float A1 = 0.5;
  float A2 = 0.4;

  generaSegnale(x1, N1, f1, f2, A1, A2);
  generaSegnale(x2, N2, f1, f2, A1, A2);

  DFT(x1, Xabs1, N1);
  DFT(x2, Xabs2, N2);

  for (int k = 0; k < N1 / 2; k++) {
    Serial.print(Xabs1[k], 2);   
    Serial.print("\t");          
    if (k < N2 / 2) {
      Serial.println(Xabs2[k], 2);
    } else {
      Serial.println();
    }
  }
  while (1);
}

void loop() {}

void generaSegnale(float x[], int N, float f1, float f2, float A1, float A2) {
  for (int n = 0; n < N; n++) {
    float t = (float)n / FS;
    x[n] = A1 * sin(2 * PI * f1 * t) + A2 * sin(2 * PI * f2 * t);
  }
}

void DFT(float x[], float Xabs[], int N) {
  for (int k = 0; k < N; k++) {
    float Re = 0, Im = 0;
    for (int n = 0; n < N; n++) {
      Re += x[n] * cos(2 * PI * k * n / N);
      Im -= x[n] * sin(2 * PI * k * n / N);
    }
    Xabs[k] = sqrt(Re * Re + Im * Im);
  }
}
