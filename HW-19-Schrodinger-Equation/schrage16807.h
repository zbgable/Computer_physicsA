#pragma once

//The header files region
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "malloc.h"
#include "time.h"
#include "windows.h"
#include "errno.h"

//Constants defination
#define M_16807 2147483647
#define PI 3.14159265358
#define EE 2.71828182846
#define ZETA 10 //initial increasing rate
#define R 1 //solution radium

//Function declaration
/**
 * @ name: int Schrage(int seed)
 *
 * @ function: generating the random number by the Schrage method
 *
 * @ parameter{seed}: seed
 *
 * @ return: the next random number
 */
int Schrage(int seed);

/**
 * @ name: int Seed()
 *
 * @ function: Using date to generate seeds
 *
 * @ return: seed
 */
int Seed();

/**
 * @ name: double *NumerovSolver(double *xSpan,int xStep,double initial,double kSquare)
 *
 * @ function: generating the random number by the Schrage method
 *
 * @ parameter{seed}: xSpan ,xStep,initial,kSquare
 *   for constant potential well V=V_0 ,double kSquare
 *   otherwise,double *kSquare
 * @ return: the wavefuction solution
 */
double *NumerovSolver(double *xSpan,int xStep,double initial,double kSquare);


void FindEigenToData(char* name,
                         double* ESpan,int EStep,
                         double *xSpan,int xStep,double* BoundCon,
                         double cutoff);

