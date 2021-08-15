/*
 * =====================================================================================
 *
 *       Filename:  Fibonacci.c
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  10/1/2020
 *       last revision: none
 *       Compiler: GNU GCC Compiler
 *
 *         Author: Bo Zhang,
 *   Organization:  USTC
 *
 * =====================================================================================
 */
#include "schrage16807.h"
double* lagged_fibonacci_generator(int p,int q,int N);

int task_1();//Adjacent numeric relation for Schrage16807
int task_2();//Adjacent numeric relation for Lagged Fibonacci Generator

int main()
{
    /*check the output of the lagged_fibonacci_generator
    int i;
    int N;
	N = (int)1e3;
	int p,q;//p>q
	p=31;
	q=3;
    double* s=lagged_fibonacci_generator(p,q,N);


    for(i=0;i<N;i++)
    {
       printf("%f\n",s[i]);
    };
    */

    task_1();
    task_2();
}
