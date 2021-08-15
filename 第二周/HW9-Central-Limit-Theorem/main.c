/*
 * =====================================================================================
 *
 *       Filename:  Central-Limit-Theorem.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/23/2020
 *       last revision: none
 *       Compiler: GNU GCC Compiler
 *
 *         Author: Bo Zhang,
 *   Organization:  USTC
 *
 * =====================================================================================
 */
#include "schrage16807.h"
 void test_central_limit_theory_2()//The function to test the central limit theorem. N=2 is the total number of random variables generated
{
    errno_t err;
	FILE* fp_sum;
	err = fopen_s(&fp_sum, " N_2.dat","w");

    int N=2;

    int n=(int)2e4;//The number of data points
    int i,j;
    double sum=0;
    int seed=Seed();//seed is not only a random seed,but also I_n .
    double rand_number;

    //direct sampling
    for(i=1;i<=n;i++)
    {
        sum=0;//Initialize sum, which is used to the sum of record n random variables

        if (i % (n / 100) == 0)
		{
			printf("Ratio %lf\n", (double)i / n);
		}

        for(j=1;j<=N;j++)
        {
            //Use the direct sampling method to generate random variables and add their values to the sum
            seed=Schrage(seed);
            rand_number=seed/M_16807;
            rand_number=2*rand_number-1;
            if(rand_number>0)
                {
                    sum+=pow(rand_number,1.0/3);
                }
            else
            {
                if(rand_number==0)
                    continue;
                else
                {
                    if(rand_number<0)
                    {
                        sum-=pow(-rand_number,1.0/3);//turn the negative to the positive
                    }
                }
            }
        }
        fprintf(fp_sum,"%6f\n",sum);
    }
    fclose(fp_sum);
}

void test_central_limit_theory_5()//The function to test the central limit theorem. N=5 is the total number of random variables generated
{
    errno_t err;
	FILE* fp_sum;
	err = fopen_s(&fp_sum, " N_5.dat","w");

    int N=5;

    int n=(int)2e4;//The number of data points
    int i,j;
    double sum=0;
    int seed=Seed();//seed is not only a random seed,but also I_n .
    double rand_number;

    //direct sampling
    for(i=1;i<=n;i++)
    {
        sum=0;//Initialize sum, which is used to the sum of record n random variables


        if (i % (n / 100) == 0)
		{
			printf("Ratio %lf\n", (double)i / n);
		}

        for(j=1;j<=N;j++)
        {
            //Use the direct sampling method to generate random variables and add their values to the sum
            seed=Schrage(seed);
            rand_number=seed/M_16807;
            rand_number=2*rand_number-1;
            if(rand_number>0)
                {
                    sum+=pow(rand_number,1.0/3);
                }
            else
            {
                if(rand_number==0)
                    continue;
                else
                {
                    if(rand_number<0)
                    {
                        sum-=pow(-rand_number,1.0/3);//turn the negative to the positive
                    }
                }
            }
        }
        fprintf(fp_sum,"%6f\n",sum);
    }
    fclose(fp_sum);
}

void test_central_limit_theory_10()//The function to test the central limit theorem. N=10 is the total number of random variables generated
{
    errno_t err;
	FILE* fp_sum;
	err = fopen_s(&fp_sum, " N_10.dat","w");

    int N=10;

    int n=(int)2e4;//The number of data points
    int i,j;
    double sum=0;
    int seed=Seed();//seed is not only a random seed,but also I_n .
    double rand_number;

    //direct sampling
    for(i=1;i<=n;i++)
    {
        sum=0;//Initialize sum, which is used to the sum of record n random variables


        if (i % (n / 100) == 0)
		{
			printf("Ratio %lf\n", (double)i / n);
		}

        for(j=1;j<=N;j++)
        {
            //Use the direct sampling method to generate random variables and add their values to the sum
            seed=Schrage(seed);
            rand_number=seed/M_16807;
            rand_number=2*rand_number-1;
            if(rand_number>0)
                {
                    sum+=pow(rand_number,1.0/3);
                }
            else
            {
                if(rand_number==0)
                    continue;
                else
                {
                    if(rand_number<0)
                    {
                        sum-=pow(-rand_number,1.0/3);//turn the negative to the positive
                    }
                }
            }
        }
        fprintf(fp_sum,"%6f\n",sum);
    }
    fclose(fp_sum);
}

void test_central_limit_theory_20()//The function to test the central limit theorem. N=20 is the total number of random variables generated
{
    errno_t err;
	FILE* fp_sum;
	err = fopen_s(&fp_sum, " N_20.dat","w");

    int N=20;

    int n=(int)2e4;//The number of data points
    int i,j;
    double sum=0;
    int seed=Seed();//seed is not only a random seed,but also I_n .
    double rand_number;

    //direct sampling
    for(i=1;i<=n;i++)
    {
        sum=0;//Initialize sum, which is used to the sum of record n random variables

        if (i % (n / 100) == 0)
		{
			printf("Ratio %lf\n", (double)i / n);
		}

        for(j=1;j<=N;j++)
        {
            //Use the direct sampling method to generate random variables and add their values to the sum
            seed=Schrage(seed);
            rand_number=seed/M_16807;
            rand_number=2*rand_number-1;
            if(rand_number>0)
                {
                    sum+=pow(rand_number,1.0/3);
                }
            else
            {
                if(rand_number==0)
                    continue;
                else
                {
                    if(rand_number<0)
                    {
                        sum-=pow(-rand_number,1.0/3);//turn the negative to the positive
                    }
                }
            }
        }
        fprintf(fp_sum,"%6f\n",sum);
    }
    fclose(fp_sum);
}

void test_central_limit_theory_50()//The function to test the central limit theorem. N=50 is the total number of random variables generated
{
    errno_t err;
	FILE* fp_sum;
	err = fopen_s(&fp_sum, " N_50.dat","w");

    int N=50;

    int n=(int)2e4;//The number of data points
    int i,j;
    double sum=0;
    int seed=Seed();//seed is not only a random seed,but also I_n .
    double rand_number;

    //direct sampling
    for(i=1;i<=n;i++)
    {
        sum=0;//Initialize sum, which is used to the sum of record n random variables

        if (i % (n / 100) == 0)
		{
			printf("Ratio %lf\n", (double)i / n);
		}

        for(j=1;j<=N;j++)
        {
            //Use the direct sampling method to generate random variables and add their values to the sum
            seed=Schrage(seed);
            rand_number=seed/M_16807;
            rand_number=2*rand_number-1;
            if(rand_number>0)
                {
                    sum+=pow(rand_number,1.0/3);
                }
            else
            {
                if(rand_number==0)
                    continue;
                else
                {
                    if(rand_number<0)
                    {
                        sum-=pow(-rand_number,1.0/3);//turn the negative to the positive
                    }
                }
            }
        }
        fprintf(fp_sum,"%6f\n",sum);
    }
    fclose(fp_sum);
}

void test_central_limit_theory_100()//The function to test the central limit theorem. N=100 is the total number of random variables generated
{
    errno_t err;
	FILE* fp_sum;
	err = fopen_s(&fp_sum, " N_100.dat","w");

    int N=100;

    int n=(int)2e4;//The number of data points
    int i,j;
    double sum=0;
    int seed=Seed();//seed is not only a random seed,but also I_n .
    double rand_number;

    //direct sampling
    for(i=1;i<=n;i++)
    {
        sum=0;//Initialize sum, which is used to the sum of record n random variables

        if (i % (n / 100) == 0)
		{
			printf("Ratio %lf\n", (double)i / n);
		}

        for(j=1;j<=N;j++)
        {
            //Use the direct sampling method to generate random variables and add their values to the sum
            seed=Schrage(seed);
            rand_number=seed/M_16807;
            rand_number=2*rand_number-1;
            if(rand_number>0)
                {
                    sum+=pow(rand_number,1.0/3);
                }
            else
            {
                if(rand_number==0)
                    continue;
                else
                {
                    if(rand_number<0)
                    {
                        sum-=pow(-rand_number,1.0/3);//turn the negative to the positive
                    }
                }
            }
        }
        fprintf(fp_sum,"%6f\n",sum);
    }
    fclose(fp_sum);
}
int main()
{
    printf("N=2\n");
    test_central_limit_theory_2();
    printf("N=5\n");
    test_central_limit_theory_5();
    printf("N=10\n");
    test_central_limit_theory_10();
    printf("N=20\n");
    test_central_limit_theory_20();
    printf("N=50\n");
    test_central_limit_theory_50();
    printf("N=100\n");
    test_central_limit_theory_100();
    system("pause");
    return 0;
}
