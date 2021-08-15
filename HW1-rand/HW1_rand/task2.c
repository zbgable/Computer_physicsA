#include "schrage16807.h"

int task2()
{
    //variables
    errno_t err_file;
	FILE* fp;
	double err;
	err_file = fopen_s(&fp, "task2.dat", "w");//save the rand_list_plot . for plotting the 2D distribution
    //initial
	double k_list[10] = { 1,2,3,4,5,6,7,8,9,10 };
	double N_list[100] = { 0.000 };
	int N_index, k_index;
	double err_list[10][100] = { 0.000 };
	double N_val, k_val;
	int i;//iterator
	int seed=Seed();//seed is not only a random seed,but also I_n .
	double sum=0.000;
	for (N_index = 0; N_index < 100; N_index++)
	{
		N_list[N_index] = N_index * 1e4;
	}
    //the relationship of power(x,k),k and N
	for (N_index = 1; N_index < 100; N_index++)
	{
		printf("task 2:  N_index = %d , total = 100\n", N_index);
		printf("sum=%f\n",sum);

		for (k_index = 0; k_index < 10; k_index++)
		{
			N_val = N_list[N_index];
			k_val = k_list[k_index];
			for (i= 0; i< N_val; i++)
			{
				seed = Schrage(seed);
				//printf("%d\n",seed);
				sum = sum + pow((double)seed/M_16807,k_val);
				//printf("%f\n",sum);
			}
			//printf("sum=%f",sum);
			err_list[k_index][N_index] = sum/N_val - 1.0/ (k_val + 1.0);
		}
	}

	//print to the file
	for (N_index = 0; N_index < 100; N_index++)
	{
		for (k_index = 0; k_index < 10; k_index++)
		{
			N_val = N_list[N_index];
			k_val = k_list[k_index];
			err = err_list[k_index][N_index];
			fprintf(fp, "%e\t%e\t%e\n", N_val, k_val, err);
		}
	}

	printf("Done\n");
	fclose(fp);

	return 0;
}
