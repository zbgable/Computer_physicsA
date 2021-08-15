
/*
 * =====================================================================================
 *
 *       Filename:  Integral-Calculation.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/19/2020
 *       last revision: none
 *       Compiler: GNU GCC Compiler
 *
 *         Author: Bo Zhang,
 *   Organization:  USTC
 *
 * =====================================================================================
 */
#include "schrage16807.h"
double one_dimen(int N)//f1(x)+1d integral,N is #sample
{
    double x1,y,sum=0;
    int i;
    int seed=Seed();

    for(i=1;i<=N;i++)
    {
        seed=Schrage(seed);
        x1=2*(double)seed/M_16807;
        y=sqrt(x1);
        //f1(x)
        y=sqrt(y+x1)-y;
        sum+=y;
    }
    sum=sum/N;//sum represents the mean of the (f(x) -g(x))
    return(2*sum+1.885618);//the integral of f1(x)
}
double five_dimen(int N)//f2(x)+5d integral,N is #sample

{
    double x1,x2,x3,x4,x5,y,sum=0;
    int i;
    int seed1,seed2,seed3,seed4,seed5;
    seed1=Seed();
    seed2=Seed()+31;
    seed1=Seed()+71;
    seed1=Seed()+11;
    seed1=Seed()+13;
    double V=0.9*0.8*0.9*2*1.3;//total volume
    //initial
    /*for(i=1;i<=N;i++)
    {
        seed1=Schrage(seed1);
        seed2=Schrage(seed2);
        seed3=Schrage(seed3);
        seed4=Schrage(seed4);
        seed5=Schrage(seed5);
    }*/

    for(i=1;i<=N;i++)
    {
        seed1=Schrage(seed1);
        seed2=Schrage(seed2);
        seed3=Schrage(seed3);
        seed4=Schrage(seed4);
        seed5=Schrage(seed5);

        x1=1.3*(double)seed1/M_16807;
        x2=2*(double)seed2/M_16807;
        x3=0.9*(double)seed3/M_16807;
        x4=0.8*(double)seed4/M_16807;
        x5=0.9*(double)seed5/M_16807;
        //f2(x)
        y=6-x1*x1-x2*x2-x3*x3-x4*x4-x5*x5;
        sum+=y;
    }
    sum=sum/N;//sum represents the mean of the f(x)
    return(V*sum-I_init);//the integral of f2(x)
}

int main()
{
    errno_t err_file;
	FILE* fp;
	FILE* fp1;


    int N_min,N_max,N_delta;
    N_min=(int)1e6;
    N_max=(int)1e7;
    N_delta=(int)2e5;
    int i;

    //generate error curves with different umbers of Monte Carlo sampling points
    //1d
    err_file = fopen_s(&fp, "1d_integral-error.dat","w");

    printf("task1:1d_integral=%6f\n",one_dimen(N_max));
    for(i=N_min;i<=N_max;i+=N_delta)
    {
        printf("Output Ratio %f\n", (double)i / (N_delta/2));
        fprintf(fp,"%6f\n",one_dimen(i)-2.6895213);
    }
    fclose(fp);

    //5d
    //err_file = fopen_s(&fp1, "5d_integral_error.dat","w");

    printf("task1:5d_integral=%6f\n",five_dimen(N_max));
    for(i=N_min;i<=N_max;i+=N_delta)
    {
        //printf("Output Ratio %f\n", (double)i/ (N_delta/2));
        printf("%6f\n",five_dimen(i)-5.64408);
        //fprintf(fp1,"%6f\n",five_dimen(i)-5.64408); fprintf will make the data wrong
    }
    //fclose(fp1);

    return 0;
}
