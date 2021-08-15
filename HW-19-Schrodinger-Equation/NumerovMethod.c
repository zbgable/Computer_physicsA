#include "schrage16807.h"

double *NumerovSolver(double *xSpan,int xStep,double initial,double kSquare)
{
    double xdelta=fabs(xSpan[1]-xSpan[0])/xStep;
    double *wave=(double*)malloc(500*sizeof(double));
    *wave=initial;
    *(wave+1)=initial + ZETA*xdelta;
    for (int i=2;i<xStep+1;i++)
    {
        *(wave+i)=*(wave+i-1)*(24-10*xdelta*xdelta*kSquare)/(12+xdelta*xdelta*kSquare)-*(wave+i-2);
        //printf("i=%d\t,phi=%.6f\n",i,*(wave+i));
    }
    return(wave);
}

