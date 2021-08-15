#include <schrage16807.h>

int task1()
{
    //variables
    errno_t err;
	FILE* fp_rand_list;
	err= fopen_s(&fp_rand_list, "task1.dat", "w");

	int N = (int)1e6;
	double* rand_list;
	rand_list = (double*)malloc(sizeof(double) * N);
	int index;
	int seed = Seed();//seed is not only a random seed,but also I_n .

    //generate random numbers
	for (index = 0; index < N; index++)
	{
		if (index % (N / 100) == 0)
			printf("Ratio = %f\n", ((double)index) / N);

		seed = Schrage(seed);
		rand_list[index] = seed/M_16807;
	}

	// task1: Plotting the 2D diagram

	for (index = 0; index < N; index++)
	{
		if (index % (N / 10) == 0)
			printf("task 1 : Print Ratio = %f\n", ((double)index) / N);
		fprintf(fp_rand_list, "%6f\n", rand_list[index]);
	}
	fclose(fp_rand_list);
	printf("Done\n");



	free(rand_list);
	return 0;
}
