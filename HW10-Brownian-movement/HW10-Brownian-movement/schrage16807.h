#pragma once

//The header files region
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "math.h"
#include "malloc.h"
#include "time.h"
#include "errno.h"

//Constants defination
#define M_16807 2147483647
#define PI 3.14159265358
#define EE 2.71828182846

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
 * @ name: double* lagged_fibonacci_generatorl()
 *
 * @ function:generating a group of rand number
 * @ parameter{p,q,N}:N is #rand
 *
 * @ return: a pointer to a group of uniform random numbers
 */
double* lagged_fibonacci_generator(int p,int q,int N);
/**
 * @ name: double* RngNormal()
 *
 * @ function:generating the standard normal distribution by Box-Muller method
 * @ parameter{u[],v[]}:
 *   x[i]=\sqrt{-2\ln u[i]}\cos 2\pi v[i]
 * @ return: a pointer to a group of normal distribution random numbers
 */
double* RngNormal();

/**
 * @ name: double* RngLorentz()
 *
 * @ function:generating the Lorentz distribution
 * @ parameter{u[]}:
 *   x[i]=\tan(\pi u[i]-\pi/2)
 * @ return: a pointer to a group of Lorentz distribution random numbers
 */
double* RngLorentz();

