#include "schrage16807.h"
double* RngLorentz()
{
     int N=1e7;
    double* rng;
    double* Lorentz;
    rng=lagged_fibonacci_generator(31,3,N);
    for(int i=0;i<N;i++)
    {
        Lorentz[i]=tan(PI*rng[i]-PI/2);
    }
   return Lorentz;
}
