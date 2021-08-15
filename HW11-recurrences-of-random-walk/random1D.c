/*  Monte Carlo Simulation of 1D simple symmetric random walk */

#include "schrage16807.h"



// random walk in 1D lattice
int RW_1D(int x)
{
    int seed=Seed();
    //Sleep(1);
	seed=Schrage(seed);
	if (seed%2==0)
    {
		return x-1;
	}
	else
		return x+1;
}

double Recur_RW_1D(int M,int n)  // M :numbers of particles ;n: the maximum walking steps
{
    int* x;
    x=malloc(sizeof(int) * M);  // x[i] is the displacement of ith particle at the n_th step.
    double Pd;    // probability of returning back to the origin point
    int count;

	printf("numbers of particles =%d,the walking steps=%d, d=1\n", M, n);
    for (int i=0; i<M; i++)
        {
            x[i]=0;
        }

	for (int step=1; step<n+1; step++)
    {
        count = 0; // count the number of particles that return back to the origin point

        for (int i=0; i<M; i++)
        {
			x[i] = RW_1D(x[i]);

			if (x[i] == 0)
			{
				count ++;
			}

		}

    }

    Pd = (double) count/M;

	return Pd;
}
