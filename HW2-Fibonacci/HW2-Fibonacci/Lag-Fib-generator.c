#include "schrage16807.h"
double* lagged_fibonacci_generator(int p,int q,int N)
{


	double* sample;
	sample = (double*)malloc(sizeof(double) * N );
	int index;
	int seed=Seed();

    //initial the array
	for (index =0 ; index < N; index++)
    {
        seed=Schrage(seed);
        sample[index]=seed;
    };
    //Fibonacci
    for (index =p ; index < N; index++)
	{
		sample[index] = fmod(sample[index - p] + sample[index - q], M_16807);

	};
	//normalization
    for (index =0 ; index < N; index++)
    {
        sample[index]=sample[index]/M_16807;
    };
	return sample;
}
