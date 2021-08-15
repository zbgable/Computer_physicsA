#include "schrage16807.h"
double* lagged_fibonacci_generator(int p,int q);

int task_2()
{
    //varibles
    errno_t err_file;
	FILE* fp;
	double err;
	err_file = fopen_s(&fp, "task-2-1e3.dat", "w");

	int N = (int)1e3;
	int count = 0;//couting the number of eligible points
	double xn;
	double xnp1=0.0; //xp1=x_n plus 1
	double xnm1=0.0;//xnm1=x_n minus 1
	int index;
	int seed=Seed();//seed is not only a random seed,but also I_n .

    double* sample=lagged_fibonacci_generator(250,103);//input p,q

    //Adjacent numeric relation
	for (index = 0; index < N; index++)
	{

		if (index % (N / 100) == 0)
		{
			printf("task_2 , index_ratio = %f\n", (double)index / N);
		}
		seed=Schrage(seed);
		xnm1 = xn;
		xn=xnp1;
		xnp1 = (double) seed / M_16807;

		if (index > 2 && (xn<xnp1) && (xnp1<xnm1))
		{
			count = count + 1;
			fprintf(fp, "%f\t%d\n",xn,1);
		}
		else
		{
			fprintf(fp, "%f\t%d\n",xn,0);
		}
	}
	printf("count=%d\n",count);
	printf("Ratio = %lf\n",(double) count / (N - 3));//only data whose own index>2 is valid
	fclose(fp);
	return 0;
}
