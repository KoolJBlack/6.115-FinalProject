import java.lang.Math; //mathematical library

// FFT parameters
public static int N_points = 64;                  //number of points        
public static float exponent =  log(64)/log(2);  //log2(N_points); for N_points=64 -> exponent=6

// FFT variables
public static float[] mod = new float[N_points];        //arrays
public static float[] data_re = new float[N_points];
public static float[] data_imm = new float[N_points];


// FFT function
void FFT(int dir,float m)
{
   // dir:  forward (=1) o inverse (!=1) transform; 
   // m exponent;
   
   int n,i,i1,j,k,i2,l,l1,l2;
   float c1,c2,tx,ty,t1,t2,u1,u2,z;

   /* Calculate the number of points */
   n = 1;
   for (i=0;i<m;i++) 
      n *= 2;

   /* Do the bit reversal */
   i2 = n >> 1;
   j = 0;
   for (i=0;i<n-1;i++) {
      if (i < j) {
         tx = data_re[i];
         ty = data_imm[i];
         data_re[i] = data_re[j];
         data_imm[i] = data_imm[j];
         data_re[j] = tx;
         data_imm[j] = ty;
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
   for ( l=0;l<m;l++) {
      l1 = l2;
      l2 <<= 1;
      u1 = 1.0; 
      u2 = 0.0;
      for ( j=0;j<l1;j++) {
         for (i=j;i<n;i+=l2) {
            i1 = i + l1;
            t1 = u1 * data_re[i1] - u2 * data_imm[i1];
            t2 = u1 * data_imm[i1] + u2 * data_re[i1];
            data_re[i1] = data_re[i] - t1; 
            data_imm[i1] = data_imm[i] - t2;
            data_re[i] += t1;
            data_imm[i] += t2;
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
         data_re[i] /= n;
         data_imm[i] /= n;
      }
   }
   
   for(i=0;i<N_points;i++)
   /* Absolute value */
   mod[i]=sqrt((data_re[i]*data_re[i])+(data_imm[i]*data_imm[i]))/N_points;   
}
