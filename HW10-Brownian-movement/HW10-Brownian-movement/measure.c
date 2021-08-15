#include "schrage16807.h"
void measure(int time,double x[],double y[],double theta[],int NumParticle,\
             double* xSqAvg, double* ySqAvg, double * thetaSqAvg, double * xSqAvgcos2t,\
             double* xSqAvgcos2tUnCor, double* ySqAvgcos2t, double* ySqAvgcos2tUnCor,\
             double* xySin2tm2, double* xySin2tm2UnCor, double* Binder_Cumulant)
             //All measurements are reference parameters
{
    //initial
    double xSqSum = 0.0, ySqSum = 0.0, thetaSqSum = 0.0, xSqC2tSum = 0.0,xySum=0.0;
    double ySqC2tSum = 0.0, xySin2tSum = 0.0, xQuadSum = 0.0, cos2tSum = 0.0, sin2tSum = 0.0;
    double currXSqSum=0.0,currXQuadSum=0.0,currYSqSum=0.0,c2t=0.0,s2t=0.0,currXY=0.0;


    //ensemble
    for (int n=0;n<NumParticle;n++)
    {
        currXSqSum = x[n] * x[n];
        currXQuadSum = currXSqSum*currXSqSum;
        currYSqSum = y[n] * y[n];
        c2t = cos(theta[n] * 2.0);
        s2t = sin(theta[n] * 2.0);
        currXY = x[n] * y[n];

        xSqSum += currXSqSum;
        xQuadSum += currXQuadSum;
        ySqSum += currYSqSum;
        thetaSqSum += theta[n] * theta[n];
        xSqC2tSum += currXSqSum*c2t;
        ySqC2tSum += currYSqSum*c2t;
        xySin2tSum += currXY * s2t;
        xySum += currXY;
        cos2tSum += c2t;
        sin2tSum += s2t;
    }
    //ensemble average
    *xSqAvg = xSqSum / time / NumParticle;
    *ySqAvg = ySqSum / time / NumParticle;
    *thetaSqAvg = thetaSqSum / time / NumParticle;
    *xSqAvgcos2t = xSqC2tSum / time / NumParticle;
    *xSqAvgcos2tUnCor = *xSqAvg * cos2tSum / NumParticle;
    *ySqAvgcos2t = ySqC2tSum / time / NumParticle;
    *ySqAvgcos2tUnCor = *ySqAvg * cos2tSum / NumParticle;
    *xySin2tm2 = 2 * xySin2tSum / time / NumParticle;
    *xySin2tm2UnCor = 2 * xySum*sin2tSum / NumParticle / NumParticle / time;
    *Binder_Cumulant = (xQuadSum * NumParticle - 3 * xSqSum * xSqSum)/ (3 * xSqSum * xSqSum);
    }

