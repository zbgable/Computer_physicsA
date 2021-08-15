#include <schrage16807.h>
/*
 * =====================================================================================
 *
 *       Filename:  schrage.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/05/2020
 *       last revision: none
 *       Compiler: GNU GCC Compiler
 *
 *         Author: Bo Zhang,
 *   Organization:  USTC
 *
 * =====================================================================================
 */
int  main()
{
    //variables
    FILE* fp;
	errno_t err;
	err = fopen_s(&fp, "theta-phi-50000.dat", "w");
	int index;
	int N;
	N = (int)5e4;
	int seed = Seed();
	double rand;
	double* x, * y, * z,* theta, * phi;

    //Initialization
    x = (double*)malloc(sizeof(double) * N);
	y = (double*)malloc(sizeof(double) * N);
	z = (double*)malloc(sizeof(double) * N);

	theta = (double*)malloc(sizeof(double) * N);
	phi = (double*)malloc(sizeof(double) * N);


	//generating theta and phi
	for (index = 0; index < N; index++)
	{
	    //printf("%d\n",seed); used to debug
        seed =Schrage(seed);
		rand = seed / M_16807;
		theta[index] = acos(rand * 2 - 1.0);
		//printf("%d\n",seed);

	}
	printf("Theta Generation Finished\n");
	for (index = 0; index < N; index++)
	{
		seed = Schrage(seed);
		rand = seed/ M_16807;
		phi[index] = rand * 2 * PI;
	}
	printf("Phi Generation Finished\n");

    //output to the file
	for (index = 0; index < N; index++)
	{
		if (index % (N / 100) == 0)
		{
			printf("Ratio = %f\n", (double)index / N);
		};
		x[index] = sin(theta[index]) * cos(phi[index]);
		y[index] = sin(theta[index]) * sin(phi[index]);
		z[index] = cos(theta[index]);
		fprintf(fp, "%6f\t%6f\t%6f\n", x[index], y[index], z[index]);
	}
	fclose(fp);
	return 0;
}
