/*
 * =====================================================================================
 *
 *       Filename:  Brownian-movement.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/30/2020
 *       last revision: none
 *       Compiler: GNU GCC Compiler
 *
 *         Author: Bo Zhang,
 *   Organization:  USTC
 *
 * =====================================================================================
 */
#include "schrage16807.h"

const int PARTICLE_NUM=1E5;//#particles used in simulation
const int TIMESTEP_MAX=2e3;//the maximum of timesteps


//D_i
double Dx=0.99;
double Dy=0.01;
double Dtheta=3e-2;

void move(double xob[],double yob[],double theta[],int NumParticle,double Dx,double Dy,double Dtheta);
void measure(int time,double x[],double y[],double theta[],int NumParticle,\
             double* xSqAvg, double* ySqAvg, double * thetaSqAvg, double * xSqAvgcos2t,\
             double* xSqAvgcos2tUnCor, double* ySqAvgcos2t, double* ySqAvgcos2tUnCor,\
             double* xySin2tm2, double* xySin2tm2UnCor, double* Binder_Cumulant);

int main()
{
    errno_t err_file;
	FILE* fp;
	double err;

    //measure and initial
    double* xSqAvg=0,*ySqAvg=0, *thetaSqAvg=0, *xSqAvgcos2t=0, *xSqAvgcos2tUnCor=0, *ySqAvgcos2t=0,\
    *ySqAvgcos2tUnCor=0, *xySin2tm2=0, *xySin2tm2UnCor=0, *Binder_Cumulant=0;



    //(x,y,theta)of all particles
    double* xob=malloc(sizeof(double) * PARTICLE_NUM);
    for (int n = 0; n < PARTICLE_NUM; n++)
    {
        xob[n] = 0;
    }
    double* yob=malloc(sizeof(double) * PARTICLE_NUM);
    for (int n = 0; n < PARTICLE_NUM; n++)
    {
        yob[n] = 0;
    }
    double* theta=malloc(sizeof(double) * PARTICLE_NUM);
    double* xcorr=malloc(sizeof(double) * TIMESTEP_MAX);//record x_correlation of each timestep
    for (int t = 0; t<TIMESTEP_MAX ; t++)
    {
        xcorr[t] = 0;
    }

    //theta0 is a uniform distribution in [0,2\pi]
    int index;
    int M=1e3;
    int timestep;
    double theta0;
    double* rng=lagged_fibonacci_generator(31,3,M);
    //theta0 average
    for(index=0;index<M;index++)
    {
        theta0=2*PI*rng[index];
        printf("%f",theta0);
        if(!(index%10)) printf("\n");

        for (int n = 0; n < PARTICLE_NUM; n++)
        {
        theta[n] = theta0;
        }

        //ensemble average
        for (timestep = 0; timestep < TIMESTEP_MAX; timestep++)
        {
            if (timestep % (TIMESTEP_MAX / 100) == 0)
            {
			printf("Ratio %f\n", (double)timestep / TIMESTEP_MAX);
            }

            //move(xob, yob, theta, PARTICLE_NUM,Dx,Dy,Dtheta);
            //measure(timestep, xob, yob, theta, PARTICLE_NUM, xSqAvg, ySqAvg, thetaSqAvg,\
            xSqAvgcos2t,xSqAvgcos2tUnCor, ySqAvgcos2t,ySqAvgcos2tUnCor, xySin2tm2,\
            xySin2tm2UnCor, Binder_Cumulant);
            //xcorr[timestep]+=*xSqAvg;
        }

    }

    //output
    //err_file = fopen_s(&fp,"x_correlation.txt", "w");
    for (timestep = 0; timestep < TIMESTEP_MAX; timestep++)
    {
        //xcorr[timestep]=xcorr[timestep]/M;
        //fprintf(fp,"%d %.6f",timestep,xcorr[timestep]);
    }
    //fclose(fp);
return 0;
}
