 #include "schrage16807.h"
double* update(double* x,double beta,double lamda)
{
    double delta_x=sigma_x*lamda;
    double delta_y=sigma_y*lamda;
    double delta_E;
    double x_try=0,y_try=0;
    double* x_new=&x_try;
    double rand_x,rand_y,rand2;
    double p_ac;

    int seed=Seed();
    seed=Schrage(seed);

    //create a x_try
    //rand_x=(double)seed/M_16807;
    rand_x=rand()/(RAND_MAX+1.0);
    x_try=*x+(rand_x-0.5) * delta_x;

    //create a y_try
    //rand_y=(double)seed/M_16807;
    rand_y=rand()/(RAND_MAX+1.0);
    y_try=*(x+1)+(rand_y-0.5)*delta_y;

    //acceptation
    delta_E=(pow(x_try,2)-pow(*x,2))/(2*sigma_x)+(pow(y_try,2)-pow(*(x+1),2))/(2*sigma_y);
    p_ac=min(1,exp(-beta*delta_E));

    //sampling
    seed=Schrage(seed);
    //rand2=(double)seed/M_16807;
    rand2=rand()/(RAND_MAX+1.0);
    //updating
    if(rand2<min(1,p_ac))
    {
        *x_new=x_try;
        *(x_new+1)=y_try;
    }
    else
    {
        *x_new=*x;
        *(x_new+1)=*(x+1);
    }

    return x_new;

}
