
#define SIG_LENGTH 320
extern double InputSignal_1kHz_15kHz[SIG_LENGTH];
double signal_mean(double *sig_src_arr,uint32_t sig_length);
double signal_varaince(double *sig_src_arr, double sig_mean, uint32_t sig_length);

void plot_signal(double *sig_src_arr, uint32_t signal_length,bool motion);

double MEAN;
double VARIANCE;

void setup() {
  Serial.begin(115200);
  //while(!SerialUSB);

MEAN  = signal_mean(&InputSignal_1kHz_15kHz[0], SIG_LENGTH/2);
VARIANCE=   signal_varaince(&InputSignal_1kHz_15kHz[0], MEAN, SIG_LENGTH/2);
Serial.print("Mean : ");
Serial.println(MEAN);
Serial.print("Variance : ");
Serial.println(VARIANCE);
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





void plot_signal(double *sig_src_arr, uint32_t signal_length,bool motion)
{
  uint32_t i;
  for(i=0;i<signal_length;i++)
  {
    Serial.println(sig_src_arr[i]); 
    if(motion)
    {
      if(i==(signal_length-1))i=0;
      }
    delay(10);
  
  }

}



double signal_varaince(double *sig_src_arr, double sig_mean, uint32_t sig_length)
{
  double _variance =0.0;
  uint32_t i;
  for(i=0;i<sig_length;i++)
  {
    _variance = _variance + powf(sig_src_arr[i]-sig_mean,2);
  }
  _variance = _variance /(sig_length-1);

  return _variance;
}

