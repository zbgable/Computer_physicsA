/*
 * =====================================================================================
 *
 *       Filename:  Gauss&Lorentzian.c
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
#include <schrage16807.h>

void Gauss()//Generating a Gaussian distribution by the acceptation sampling
{
    //variables
    errno_t err_file;
	FILE* fp;
	double err;


    int N=(int)1e5;
    int count_total=0;//count the  #points, to calculate the total sampling efficiency
    int count_rej=0;//count the #ponints of rejection at the second sampling, to calculate the second sampling efficiency
    double x_1,x_2,x,x2,y_1,y,eff1,eff2;
    int i;
    int seed1=Seed();
    int seed2=seed1+3;
    int seed3=seed1+7;

    for(i=0;i<=N;i++)
    {
        if (i % (N / 100) == 0)
		{
			printf("Ratio = %f\n", (double)i / N);
		}
        //calculate the total #points
        count_total++;
        //generating a random point x of lorentzian distribution  by the multiplication distribution method
        err_file = fopen_s(&fp,"lorentzian.dat" "d", "w");
        seed1=Schrage(seed1);
        x_1=(double)seed1/M_16807;
        seed2=Schrage(seed2);
        x_2=(double)seed2/M_16807;

        x=tan(PI*(x_1-0.5));
        x2=x*x;

        if(3.8*x_2<=PI*(1+x2)/(1+x2*x2))
        {
            fprintf(fp, "%f\n",x);
        }
        else
        {
            //rejecting the point
            i--;
            continue;
        }
        fclose(fp);
        //generating a Gauss distribution by the acceptation sampling
        err_file = fopen_s(&fp,"Gaussian.dat" "d", "w");
        seed3=Schrage(seed3);
        y_1=(double)seed3/M_16807;
        y=y_1/(1+x2*x2);
        if(y<pow(EE,-x2/2)/sqrt(2*PI))
        {
            fprintf(fp,"%f\n",y);
        }
        else
        {
            //rejecting the point
            i--;
            count_rej++;
            continue;
        }
    }
    //output the efficiency
    eff1=(double)N/count_total;
    printf("the total efficiency of sampling is %f\n",eff1);
    eff2=(double)N/(count_rej+N);
    printf("the efficiency of the second sampling is %f",eff2);
    fclose(fp);
}

int main()
{
    Gauss();
}
