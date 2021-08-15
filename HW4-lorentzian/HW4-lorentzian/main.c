/*
 * =====================================================================================
 *
 *       Filename:  lorentzian.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/06/2020
 *       last revision: none
 *       Compiler: GNU GCC Compiler
 *
 *         Author: Bo Zhang,
 *   Organization:  USTC
 *
 * =====================================================================================
 */
#include <schrage16807.h>
int main()
{
    //variables
    FILE* fp;
	errno_t err;
	err = fopen_s(&fp, "Lorentzian.dat", "w");

	int N;
	N = (int)1e6;
	int index;
	int seed=Seed();//seed is not only a random seed,but also I_n .
	double x;//the rand for Lorentz's distribution

    //output to the file
	for (index = 0; index < N; index++)
	{
		if (index % (N / 100) == 0)
		{
			printf("Ratio = %f\n",(double) index / N);
		}
		seed=Schrage(seed);
		x = tan(((double)seed / N - 0.5) * PI);
		fprintf(fp,"%6e\n", x);
	}
	fclose(fp);
	return 0;

}
