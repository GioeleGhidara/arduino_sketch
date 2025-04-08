
#define SIG_LENGTH 320
extern double InputSignal_1kHz_15kHz[SIG_LENGTH];
double signal_mean(double *sig_src_arr,uint32_t sig_length);
double MEAN;

void setup() {
  Serial.begin(115200);
//  for(int i = 0;i<SIG_LENGTH;i++)
//  {
//   Serial.println(InputSignal_1kHz_15kHz[i]);
//   delay(5);  
//  
//  }
MEAN  = signal_mean(&InputSignal_1kHz_15kHz[0], SIG_LENGTH);
Serial.print("Mean : ");
Serial.println(MEAN);

}

void loop() {

}

double signal_mean(double *sig_src_arr,uint32_t sig_length)
{
  double _mean =0.0;
  uint32_t i;  
  for(i=0;i<sig_length;i++)
  {
  _mean  = _mean + sig_src_arr[i];
  }

  _mean = _mean /(double)sig_length;
  
 return _mean;
}

