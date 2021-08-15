/*
 * =====================================================================================
 *
 *       Filename:  Metropolis Hasting sampling.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  11/25/2020
 *       last revision: none
 *       Compiler: GNU GCC Compiler
 *
 *         Author: Bo Zhang,
 *   Organization:  USTC
 *
 * =====================================================================================
 */
 #include "schrage16807.h"
int count=0;//to count the efficiency
double MH_sampling(double x,double gamma);
int main()
{
    errno_t err_file;
	FILE* fp;
	double err;

    double gamma=5;
    int N_samp=1e6;//#sampling
    int N_warm=1e5;//#warm
    int epoch=1e2;
    double sum=0;//to calculate I
    double error=0;//to calculate |I-alpha*beta^2|
    double acce;//acceptation
    double x_sam=1;


/*
//different N_samp:
    err_file = fopen_s(&fp,"error--N_samp.txt","w");

    for(int n=3;n<8;n++)
    {
        N_samp=pow(10,n);
        sum=0;
        for(int i=0;i<N_warm;i++)
        {
        //printf("%f\n",x_sam);
        x_sam=MH_sampling(x_sam,gamma);
        }
    count=0;
    for(int i=0;i<N_samp;i++)
        {
        x_sam=MH_sampling(x_sam,gamma);
        sum+=(x_sam-alpha*beta)*(x_sam-alpha*beta);
        }

    sum=sum/N_samp;
    error=fabs(sum-alpha*beta*beta);
    acce=(double)count/N_samp;
    //error=sum-alpha*beta*beta;
    printf("N_samp=%d,I=%f,error=%f\n",N_samp,sum,error);
    printf("acceptation=%.6f\n",acce);
    fprintf(fp,"%d,%.6f,%.6f,%.6f\n",N_samp,sum,error,acce);

    }
    fclose(fp);
*/

//different gamma:
    err_file = fopen_s(&fp,"error--gamma-200.txt","w");

    for(gamma=1;gamma<200;gamma++)
    {
         sum=0;
         for(int i=0;i<N_warm;i++)
        {
        //printf("%f\n",x_sam);
        x_sam=MH_sampling(x_sam,gamma);
        }
    count=0;
    for(int i=0;i<N_samp;i++)
        {
        x_sam=MH_sampling(x_sam,gamma);
        sum+=(x_sam-alpha*beta)*(x_sam-alpha*beta);
        }

    sum=sum/N_samp;
    error=fabs(sum-alpha*beta*beta);
    acce=(double)count/N_samp;
    //error=sum-alpha*beta*beta;
    printf("gamma=%.6f,I=%f,error=%f\n",gamma,sum,error);
    printf("acceptation=%.6f\n",acce);
    fprintf(fp,"%.6f,%.6f,%.6f,%.6f\n",gamma,sum,error,acce);
    }
    fclose(fp);




}
