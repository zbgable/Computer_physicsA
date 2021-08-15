/*
 * =====================================================================================
 *
 *       Filename: Schrodinger-Equation-solver .c
 *
 *    Description:
 j
 *
 *        Version:  1.0
 *        Created:  1/3/2020
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

    double xSpan[]={-R,R};
    double BoundCon[]={0,0};
    double ESpan[]={1,40};
    double cutoff=1E-3,E,kSquare;

    int xStep=200,EStep=4000;

    FindEigenToData("data0/data",ESpan,EStep,xSpan,xStep,BoundCon,cutoff);


    return 0;
}


