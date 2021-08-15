/*
 * =====================================================================================
 *
 *       Filename:  Markov Chain.c
 *
 *    Description:
 j
 *
 *        Version:  1.0
 *        Created:  12/08/2020
 *       last revision: none
 *       Compiler: GNU GCC Compiler
 *
 *         Author: Bo Zhang,
 *   Organization:  USTC
 *
 * =====================================================================================
 */
#include "schrage16807.h"
double* update(double* x,double beta,double lamda);
int main()
{
    errno_t err_file;
	FILE* fp;
	double err;

    double beta=1000;//the temperature
    double lamda=4;// control the update paces
    int N_samp=1e5;//#sampling
    int N_warm=1e6;//#warm
    int epoch=1e2;
    double error_x=0,error_y=0,error_xy=0;//to calculate the errors

    double acce;//acceptation
    double x_samp=0;
    double* x_sam=&x_samp;//the initial sample point
    *(x_sam+1)=0;
    //warm up

    for(int i=0;i<N_warm;i++)
        {
        //printf("%f\n",x_sam);
        x_sam=update(x_sam,beta,lamda);
        }

    printf("warm up\n");
    //update
    err = fopen_s(&fp, "lamda=4,beta=1000.txt", "w");
    for(int i=0;i<N_samp;i++)
        {
        x_sam=update(x_sam,beta,lamda);

        if (i % (N_samp / 100) == 0)
		{
			printf("Ratio = %f\n",(double) i / N_samp);

		}
		printf("step=%d,x=%.6f,y=%.6f\n",i,x_sam[0],x_sam[1]);
		fprintf(fp,"x=%.6f,y=%.6f\n",x_sam[0],x_sam[1]);
        }

/*
//different lamda:
    for(lamda=0.1;lamda<4.5;lamda+=0.5)
    {
    }
//different N_samp;
    for(N_samp=1e5;N_samp<7e5;N_samp+=5e4)
    {
    }
//different beta;



*/
}
