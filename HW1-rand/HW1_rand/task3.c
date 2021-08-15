#include "schrage16807.h"

int task3()
{
    //variables
    errno_t err_file;
	FILE* fp;
	double err;
	err_file = fopen_s(&fp, "task3.dat", "w");

	int N;
	N = (int)1e6;
	int i;
	int seed=Seed();//seed is not only a random seed,but also I_n .
	double* rand_list;
	rand_list = (double*)malloc(sizeof(double) * N);
	int index;
	//generating a rand array
	for (index = 0; index < N; index++)
	{
		seed = Schrage(seed);
		rand_list[index] = seed/M_16807;
	}

	//correlation
	double* correlation_list;
	int NumCorr=100;
	int L;// L = 0,1,2,3....99 represents the length of correlation
	correlation_list = (double*)malloc(sizeof(double) * NumCorr);

	double  x_n, x_n_npl, x_n2, x_2n;
    x_n = 0.0;
	x_n_npl = 0.0;//x_n*x_(n+L)
	x_n2 = 0.0;//(x_n)^2
	x_2n = 0.0;//(x^2)_n

	for (index = 0; index < N; index++)
	{
		x_n = x_n + (double) rand_list[index] / N;
		x_2n = x_2n + (double)rand_list[index] * rand_list[index] / N;
	}
	x_n2 = x_n * x_n;

	for (L = 0; L < NumCorr; L++)
	{
		printf("task 3 L = %d\n", L);
		x_n_npl = 0.0;

		for (i = 0; i < (N - L); i++)
		{
			x_n_npl = x_n_npl + rand_list[i] * rand_list[i + L] / (N - L);
		}
		correlation_list[L] = (x_n_npl - x_n2) / (x_2n - x_n2);
	}

	//output to the file
	for (index = 0; index < NumCorr; index++)
	{
		fprintf(fp, "%e\t%e\n", (double)index, correlation_list[index]);
	}
	printf("Done\n");
	fclose(fp);

	return 0;
}
