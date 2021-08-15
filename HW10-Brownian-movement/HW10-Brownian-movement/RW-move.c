#include "schrage16807.h"

//three independent random walks in continuous space
void move(double xob[],double yob[],double theta[],int NumParticle,double Dx,double Dy,double Dtheta)
{
    for(int i=0;i<NumParticle;i++)
    {
        //movement in body frame
        double CosThetaI=cos(theta[i]);
        double SinThetaI=sin(theta[i]);
        double delta_x=Dx*RngNormal()[i];
        double delta_y=Dy*RngNormal()[i];
        //coordinate transformation
        xob[i]+=delta_x*CosThetaI-delta_y*SinThetaI;
        yob[i]+=delta_x*SinThetaI+delta_y*CosThetaI;
        //random walk of theta
        theta[i]+=Dtheta*RngNormal()[i];
        //printf("%f %f %f\n",xob[i],yob[i],theta[i]);
    }
}
