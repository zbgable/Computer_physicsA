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

