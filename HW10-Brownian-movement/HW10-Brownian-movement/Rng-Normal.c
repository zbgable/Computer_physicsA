#include "schrage16807.h"
double* RngNormal()
{
    int N=1e7;
    double* rng;
    double* Gaussian;
    rng=lagged_fibonacci_generator(31,3,N);
    for(int i=0;i<N-1;i++)
    {
        Gaussian[i]=sqrt(-2.0*log(rng[i]))*cos(2.0*PI*rng[i+1]);
    }
    return Gaussian;
}


