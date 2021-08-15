 #include "schrage16807.h"
 int count;
double MH_sampling(double x,double gamma)
{

    double x_sam,x_new;
    double rand1,rand2;
    double p_ac;
    int seed=Seed();
    seed=Schrage(seed);
    //create a x_sam
    //rand1=(double)seed/M_16807;
    rand1=rand()/(RAND_MAX+1.0);
    x_sam=-gamma*log(rand1);
    //acceptation
    p_ac=pow((x_sam/x),(alpha-1))*exp(-(x_sam-x)/beta)*exp((x_sam-x)/gamma);

    //sampling
    seed=Schrage(seed);
    //rand2=(double)seed/M_16807;
    rand2=rand()/(RAND_MAX+1.0);
    if(rand2<min(1,p_ac))
    {
        x_new=x_sam;
        count++;
    }
    else
    {
        x_new=x;
    }

    return x_new;

}
