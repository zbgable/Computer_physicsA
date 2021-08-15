/*
 * =====================================================================================
 *
 *       Filename:  Experiment.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/8/2020
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
    //The variables
    FILE* fp;
	errno_t err;


	double x_val, y_val;
	x_val = 0.0;
	y_val = 0.0;
	int seed=Seed();
	int E_data,index;
	E_data = 114;//the energy range
	double* E_list, *y_list;
	E_list = (double*)malloc(sizeof(double) * E_data);
	y_list = (double*)malloc(sizeof(double) * E_data);
    int N=5e4;//the number of #rand generation
    double* data_new;
	data_new = (double*)malloc(sizeof(double) * N);
	double rand_double;
	int check_index;

    //reading the data from the file
    err = fopen_s(&fp, "data.txt", "r");
	for (index = 0; index < E_data; index++)
	{
		fscanf_s(fp, "%lf\t%lf\n", &x_val, &y_val);
		E_list[index] = x_val;
		y_list[index] = y_val;
		printf("%f\t%f\n", x_val, y_val);
	};
	fclose(fp);
	printf("Data Reading Finished ");

    //direct sampling
	//Creating the scales to allocate the #rand directly
	double sum_y;
	sum_y = 0;
	double* scale;
	scale = (double*)malloc(sizeof(double) * E_data);
	int index_inside;
	for (index = 0; index < E_data; index++)
	{
		sum_y = sum_y + y_list[index];
	}


	for (index = 0; index < E_data; index++)
	{
		scale[index] = 0.0;
		for (index_inside = 0; index_inside <= index; index_inside++)
		{
			scale[index] = scale[index] + y_list[index_inside];
		}
		scale[index] = scale[index] / sum_y;
	}
	printf("Scale Generating Finished\n");

    //create the new data directly
	for (index = 0; index < N; index++)
	{
		if (index % (N / 100) == 0)
		{
			printf("New Generation Ratio %f\n",(double) index / N);

		}
        seed = Schrage(seed);
        rand_double = (double)seed / M_16807;

		for (check_index = 0; check_index < E_data; check_index++)
		{
			if (rand_double < scale[check_index])
			{
				data_new[index] = E_list[check_index];
				break;
			}
		}
	}

    //output to the file
	err = fopen_s(&fp, "data_new_directly.txt", "w");
	for (index = 0; index < N; index++)
	{
		if (index % (N / 100) == 0)
		{
			printf("Output Ratio %f\n", (double)index / N);
		}
		fprintf(fp, "%6e\n", data_new[index]);
	}
	fclose(fp);

	// acceptance sampling
	double max_freq,min_E,max_E;
	max_freq = 0;
	min_E = E_list[0];
	max_E = E_list[E_data - 1];
	for (index = 0; index < E_data; index++)//find out where the max y_value locates
	{
		if (y_list[index] > max_freq)
		{
			max_freq = y_list[index];
		}
	}
	//Then we would like to have two random integers in the region
	double* data_AC;
	data_AC = (double*)malloc(sizeof(double) * N);
	int x_try, y_try;
	int accept_sign = 0;
	int total_count;
	for (index = 0; index < N; index++)
	{
		if (index % (N / 100) == 0)
		{
			//printf("Acceptance Sampling Ratio %lf\n", (double)index / N);
		}
		accept_sign = 0;
		while (accept_sign == 0)
		{
			seed = Schrage(seed);
			x_try = seed % E_data;
			seed = Schrage(seed);
			y_try = seed % (int)max_freq;
			total_count++;
			if (y_try < y_list[x_try])
			{
				data_AC[index] = E_list[x_try];
				accept_sign = 1;
			}

		}
	}

	//output to the file
	err = fopen_s(&fp, "data_new_acceptance.txt", "w");
	for (index = 0; index < N; index++)
	{
		if (index % (N / 100) == 0)
		{
			//printf("Output Ratio %lf\n", (double)index / N);
		}
		fprintf(fp, "%lf\n", data_AC[index]);
	}
	fclose(fp);
	//output the efficiency
	printf("the efficiency of the acceptance sampling is %f",(double)N/total_count);

	return 0;
}

