/*
 * =====================================================================================
 *
 *       Filename:  polar-projection.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/07/2020
 *       last revision: none
 *       Compiler: GNU GCC Compiler
 *
 *         Author: Bo Zhang,
 *   Organization:  USTC
 *
 * =====================================================================================
 */
#include "schrage16807.h"

int main()
{
    errno_t err;
	FILE* fp;
	err = fopen_s(&fp, "50000.dat", "w");
	int N;
	N = (int)5e4;
	int seed1 =Seed();
	int seed2=seed1+7;
	int i;
	double u, v, r2, x, y, z;

	for (i = 0; i < N; i++)
	{
		if (i % (N / 100) == 0)
		{
			printf("Ratio = %f\n",(double) i / N);
		};
		seed1 = Schrage(seed1);
		u =2.0* seed1 / M_16807 - 1.0;
		seed2 = Schrage(seed2);
		v =2.0* seed2 /M_16807  - 1.0;
		r2 = u * u + v * v;
		if (r2 <= 1)
		{
			x = 2 * u * sqrt(1 - r2);
			y = 2 * v * sqrt(1 - r2);
			z = 1.0 - 2 * r2;
			fprintf(fp, "%f\t%f\t%f\n", x, y, z);
		}
	}
	fclose(fp);
	return 0;
}

