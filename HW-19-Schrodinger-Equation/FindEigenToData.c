#include "schrage16807.h"
void FindEigenToData(char* name,
                         double* ESpan,int EStep,
                         double *xSpan,int xStep,double* BoundCon,
                         double cutoff)
{
    double Edelta=(ESpan[1]-ESpan[0])/(double)EStep;
    char nameEnum[10];
    char *nameIter,*nameE="_E_",*nameDat=".dat";
    //strcat(nameIter,name);strcat(nameIter,nameE);
    double * phi;
    double E,kSquare;

    FILE *fp;

    //increasing the energy_trial
    int i,j,ENum=0;
    int nameLen=strlen(nameIter);
    /*
    for (int i = 0; i < EStep+1; i++)
    {

        E=ESpan[0]+Edelta*i;
        kSquare=2*E;
        //kSquare[i]=2*(E-V[i])
        phi=NumerovSolver(xSpan,xStep,BoundCon[0],kSquare);
        printf("%f\n",*(phi+xStep));
        //to find the eigenvalue
        if (fabs(BoundCon[1]-phi[xStep])<cutoff)
        {
            //get the name of output file

            nameIter[nameLen]=0;
            ENum++;
            printf("n=%d\t E=%.6f\n",ENum,E);
        }
    */
        //check
        for(ENum=1;ENum<6;ENum++)
        {

        kSquare=ENum*ENum*PI*PI/4;
        phi=NumerovSolver(xSpan,xStep,BoundCon[0],kSquare);
        E=kSquare/2;
        printf("E=%f\t,error=%f\n",E,fabs(*(phi+xStep)));
        }

            nameIter[nameLen]=0;
            strcat(nameIter,itoa(ENum,nameEnum,10));//transform value to string
            strcat(nameIter,nameDat);

            /*
            if ((fp = fopen(nameIter, "w")) == NULL)
	        {
		        exit(0);
	        }

            //output
            //eigenvalue E_n
            fprintf(fp," %.6f\n",E);
            //eigenfuction phi_n
            for (int j = 0; j < xStep+1; j++)
            {
                fprintf(fp,"%f\n",*(phi+j));
            }
            fprintf(fp,"\n");
            fclose(fp);
            */
            free(phi);



}
