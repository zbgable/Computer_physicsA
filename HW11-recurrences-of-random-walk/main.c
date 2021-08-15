/*
 * =====================================================================================
 *
 *       Filename:  The-recursion-of-RW.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  11/01/2020
 *       last revision: none
 *       Compiler: GNU GCC Compiler
 *
 *         Author: Bo Zhang,
 *   Organization:  USTC
 *
 * =====================================================================================
 */
#include "schrage16807.h"
int RW_1D(int x,int N);
int RW_2D(int x,int N);
int RW_3D(int x,int N);
double Recur_RW_1D(int M,int n);
double Recur_RW_2D(int M,int n);
double Recur_RW_3D(int M,int n);

int main()
{
    errno_t err_file;
	FILE* fp;
	double err;

    int M=1e5;//M :numbers of particles ;
    int N=200;//N: the maximum walking steps
    double Pd;    // probability of returning back to the origin point
    //check RW function
    /*
    int m[3]={0,0,0};
    m[3]=RW_3D(m,N);
    for(int i=0;i<3;i++)
    {
         printf("%d\n",m[i]);
    }
    */
    //1D random walk
    //err_file = fopen_s(&fp,"1DN200M10000.txt", "w");
    printf("1d_RW\n");
    for (int n=1; n<N+1; n++)
    {
        Pd=Recur_RW_1D(M,n);
		printf("行走%d步,回到原点的概率%0.6lf\n", n,Pd);
		//fprintf(fp,"%d,%0.6lf\n", n,Pd);

	}
	//fclose(fp);

//2D random walk
    //err_file = fopen_s(&fp,"2DN200M10000.txt", "w");
    printf("2d_RW\n");
    for (int n=1; n<N+1; n++)
    {
        Pd=Recur_RW_2D(M,n);
		printf("行走%d步,回到原点的概率%0.6lf\n", n,Pd);
		//fprintf(fp,"%d,%0.6lf\n", n,Pd);

	}
	//fclose(fp);

//3D random walk
    //err_file = fopen_s(&fp,"3DN200M10000.txt", "w");
    printf("3d_RW/n");
    for (int n=1; n<N+1; n++)
    {
        Pd=Recur_RW_3D(M,n);
		printf("行走%d步,回到原点的概率%0.6lf\n", n,Pd);
		//fprintf(fp,"%d,%0.6lf\n", n,Pd);

	}
	//fclose(fp);

    return 0;
}
