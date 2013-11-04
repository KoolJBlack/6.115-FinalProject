#include <math.h>				 //mathematical library

// FFT parameters
#define N_points (128)              //number of points				
#define exponent log(128)/log(2)  //log2(N_points); for N_points=64 -> exponent=6
#define N_avg (8)          // Number of points to average into one value

// FFT variables
double mod[N_points]={0};        //arrays
double data_re[N_points]={0};
double data_imm[N_points]={0};

int mod_avg[N_points/N_avg] = {0};

// FFT function
short FFT(int dir,long m,double *x,double *y)
{
   // dir:  forward (=1) o inverse (!=1) transform; 
   // m exponent;
   
   long n,i,i1,j,k,i2,l,l1,l2;
   double c1,c2,tx,ty,t1,t2,u1,u2,z;

   /* Calculate the number of points */
   n = 1;
   for (i=0;i<m;i++) 
      n *= 2;

   /* Do the bit reversal */
   i2 = n >> 1;
   j = 0;
   for (i=0;i<n-1;i++) {
      if (i < j) {
         tx = x[i];
         ty = y[i];
         x[i] = x[j];
         y[i] = y[j];
         x[j] = tx;
         y[j] = ty;
      }
      k = i2;
      while (k <= j) {
         j -= k;
         k >>= 1;
      }
      j += k;
   }

   /* Compute the FFT */
   c1 = -1.0; 
   c2 = 0.0;
   l2 = 1;
   for (l=0;l<m;l++) {
      l1 = l2;
      l2 <<= 1;
      u1 = 1.0; 
      u2 = 0.0;
      for (j=0;j<l1;j++) {
         for (i=j;i<n;i+=l2) {
            i1 = i + l1;
            t1 = u1 * x[i1] - u2 * y[i1];
            t2 = u1 * y[i1] + u2 * x[i1];
            x[i1] = x[i] - t1; 
            y[i1] = y[i] - t2;
            x[i] += t1;
            y[i] += t2;
         }
         z =  u1 * c1 - u2 * c2;
         u2 = u1 * c2 + u2 * c1;
         u1 = z;
      }
      c2 = sqrt((1.0 - c1) / 2.0);
      if (dir == 1) 
         c2 = -c2;
      c1 = sqrt((1.0 + c1) / 2.0);
   }

   /* Scaling factor for forward transform */
   if (dir == 1) {
      for (i=0;i<n;i++) {
         x[i] /= n;
         y[i] /= n;
      }
   }
   
   for(i=0;i<N_points;i++)
   /* Absolute value */
   mod[i]=sqrt((data_re[i]*data_re[i])+(data_imm[i]*data_imm[i]))/N_points;   
}


void ResetFFT(){
  int i;
  for(i=0;i<N_points;i++){    
  mod[i]=0;       //init 0
  data_re[i]=0;
  data_imm[i]=0;
  }
}


void FFTAVG(){
    int i = 0;
    int j = 0;
    for(i = 0; i < N_points/N_avg; ++i){
        mod_avg[i] = 0;
        
        // For the averages, skip the first bucket.
        if( i != 0){
            for(j = 0; j < N_avg; ++j){
                mod_avg[i] += mod[i*N_avg +j];
            }
            //mod_avg[i] /= N_avg;
         }else{
            for(j = 1; j < N_avg; ++j){
                mod_avg[i] += mod[i*N_avg +j];
            }
            //mod_avg[i] /= N_avg;
         }
    }
}