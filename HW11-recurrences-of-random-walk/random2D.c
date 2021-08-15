/*  Monte Carlo Simulation of 2D simple symmetric random walk */


#include "schrage16807.h"


// random walk in 2D square lattice
int RW_2D(int x[2])
{

	int seed=Seed();
	//Sleep(1);
	seed=Schrage(seed);
	switch (seed%4)
	{
		case 0: x[0] -= 1; break;
		case 1: x[0] += 1; break;
		case 2: x[1] -= 1; break;
		case 3: x[1] += 1; break;
		default: printf("error\n");
	}
	return 0;
}

double Recur_RW_2D(int M,int n)  // M :numbers of particles ;n: the maximum walking steps
{
    int (*x)[2]=(int(*)[2]) malloc(sizeof(int)*M*2) ;// x[i] is displacement of ith particle at n moment
	double Pd;    // probability of returning origin point

	printf("numbers of particles =%d,the walking steps=%d, d=2\n", M, n);
	for (int i=0; i<M; i++)
        {
            x[i][0]=0;
            x[i][1]=0;
        }

	for (int step=1; step<n+1; step++)
    {
		int count = 0;	// count the numbers return to the origin

		for (int i=0; i<M; i++)
        {
			RW_2D(x[i]);
			if ((x[i][0]==0)&&(x[i][1]==0)){
				count ++;
			}
		}
		Pd = (double) count/M;

	}
	return Pd;
}
