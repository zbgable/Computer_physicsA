/*
 * =====================================================================================
 *
 *       Filename:  .c
 *
 *    Description:
 j
 *
 *        Version:  1.0
 *        Created:  12/09/2020
 *       last revision: none
 *       Compiler: GNU GCC Compiler
 *
 *         Author: Bo Zhang,
 *   Organization:  USTC
 *
 * =====================================================================================
 */
 #include "schrage16807.h"
int main()
 {

    errno_t err_file;
	FILE* fp;
	double err;

	double x=0.15;    	/*initial value of x*/
	int count = 0;    	/*to count the number of data point*/
	double Min=0.0, Max=2.0;    /*the range of lambda is [min, max]*/
	int Num=50;            /*the number of x to print out for each lambda*/
	double Step=0.01;        /*the step of lambda*/


	//some information about the input
	/*
	fprintf(stderr, "Please input some parameters.\n The number of data points N = (Max-Min)*Num*Step \n");
	fprintf(stderr, "Min(the min of lambda): ");
	scanf("%lf", &Min);
	fprintf(stderr, "Max(the max of lambda): ");
	scanf("%lf", &Max);
	fprintf(stderr, "Num(the number of x to print out for each lambda): ");
    scanf("%d", &Num);
	fprintf(stderr, "Step(the step of lambda): ");
	scanf("%lf", &Step);
    printf("%f, %f\n %d, %f\n", Min, Max, Num, Step);
    */

    err_file = fopen_s(&fp,"min0.0max2.0num50.0step0.01.txt","w");
    fprintf(fp,"%.6f","%.6f\n",Min,Max);
    fprintf(fp,"%d,%.6f\n",Num,Step);
	for (double lambda = Max; lambda > Min; lambda = lambda-Step)
    {
		for (int i=0; i<ITERATION_NUM; i++)
		{
			x = lambda*sin(PI*x);   		  /*iteration equation*/
			if (i>(ITERATION_NUM-Num-1))
            {
				printf("lamda=%.6f, x=%.6f\n", lambda, x);
 	            /*print out the last some iterative values of x */
 	            fprintf(fp,"%.6f","%.6f\n",lambda,x);
				count++;
			}
		}
	}
	/*print out the number of all data points.*/
	fclose(fp);
	return 0;
}
