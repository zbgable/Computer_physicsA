#include "schrage16807.h"

//Linear Congruence Method
int azmodm(int a, int z, int m, int q, int r)
{
    int t;
	t= a * (z % q) - r * (z / q);
	if (t < 0) t += m;
	return t;
}

// The Random Number Generator
int Schrage(int seed)
{
	int a, b,m, q, r,mod;
	a = 16807;
	b = 0;
	m=M_16807;

	// Calculate other parameters

    q = m / a;
    r = m % a;


	//if error then return -1

	if (seed<0)
	{
		return -1;
	}

	//mod = azmodm(a,seed,m,q,r);
    mod=rand();
	return mod;
}


int Seed()
{
	int seed;
	time_t rawtime;
	struct tm* info;

	//get the time
	time(&rawtime);

	//translate to the local time
	info = localtime(&rawtime);
	info->tm_year = info->tm_year % 100;

	//compute the seed
	seed = info->tm_year + 70 * (info->tm_min + 12 * (info->tm_mday\
		+ 31 * (info->tm_hour + 23 * (info->tm_min + 59 * (info->tm_sec)))));
	return seed;
}
