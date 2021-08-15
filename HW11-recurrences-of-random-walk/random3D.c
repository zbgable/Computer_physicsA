/*  Monte Carlo Simulation of 3D simple symmetric random walk */


#include "schrage16807.h"


// random walk in 3D cubic lattice
int RW_3D(int x[3]) {
	int seed=Seed();
	//Sleep(1);
	seed=Schrage(seed);
	switch (seed%6)
	{
		case 0: x[0] -= 1; break;
		case 1: x[0] += 1; break;
		case 2: x[1] -= 1; break;
		case 3: x[1] += 1; break;
		case 4: x[2] -= 1; break;
		case 5: x[2] += 1; break;
		default: printf("error!\n");
	}
	return 0;
}


double Recur_RW_3D(int M,int n)  // M :numbers of particles ;n: the maximum walking steps
{
    int (*x)[3]=(int(*)[3]) malloc(sizeof(int)*M*3) ;  // x[i] is displacement of ith particle at t moment
	double Pd;    // probability of returning origin point

	printf("numbers of particles =%d,the walking steps=%d, d=3\n", M, n);
	for (int i=0; i<M; i++)
        {
            x[i][0]=0;
            x[i][1]=0;
            x[i][2]=0;
        }

	for (int step=1; step<n+1; step++) {
		int count = 0; // count the number of particles return to Origin

		for (int i=0; i<M; i++) {
			RW_3D(x[i]);
			if ((x[i][0]==0)&&(x[i][1]==0)&&(x[i][2]==0)){
				count ++;
			}
		}
		Pd = (double) count/M;

	}
	return Pd;
}
