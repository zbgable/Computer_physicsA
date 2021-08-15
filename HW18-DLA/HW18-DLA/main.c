/*
 * =====================================================================================
 *
 *       Filename: DLA .c
 *
 *    Description:
 j
 *
 *        Version:  1.0
 *        Created:  12/21/2020
 *       last revision: none
 *       Compiler: GNU GCC Compiler
 *
 *         Author: Bo Zhang,
 *   Organization:  USTC
 *
 * =====================================================================================
 */
 #include "schrage16807.h"

// define some global variables
int center = (int) RANGE/2;
int maxcoor = 0, mincoor = 0;
// initialize the particle_set to 0
int particle_set[RANGE][RANGE] = {};

// random walk function
int random_walk(int *x, int *y);

int new_particle(int *x, int *y)
{
    int seed=Seed();
    seed=Schrage(seed);//#rand
	int num = (seed%(maxcoor-mincoor+2*DIST))+mincoor;
	switch (seed%4)
	{
		case 0:
			*x=maxcoor+DIST, *y=num;
			break;
		case 1:
			*y=maxcoor+DIST, *x=num;
			break;
		case 2:
			*x=mincoor-DIST, *y=num;
			break;
		case 3:
			*y=mincoor-DIST, *x=num;
			break;
	}
//	printf("new particle is x = %d, y = %d\n", *x, *y);
}


int th_max(int x, int y, int z)
{
	int temp=0;
	if (x >= y)
		temp = x;
	else
		temp = y;
	if (z >= temp) temp=z;

    return temp;
}

int th_min(int x, int y, int z)
{
	int temp=0;
	if (x >= y)
		temp = y;
	else
		temp = x;
	if (z <= temp) temp=z;

    return temp;
}

//judge the escape or aggregation of the particle
int aggregate_or_escape(int x, int y, int a[RANGE][RANGE], int *count)
{
	if (x>maxcoor+DIST || x<mincoor-DIST || y>maxcoor+DIST || y<mincoor-DIST)
    {
//		printf("particle escaped!\n");
		return 0;
	}
	else if (a[x-1][y]==1||a[x+1][y]==1||a[x][y-1]==1||a[x][y+1]==1)
    {
		a[x][y] = 1;
		(*count)++;
		printf("particle-particle aggregation!\n");
		printf("%d, %d\n", x, y);
		maxcoor = th_max(x, y, maxcoor);
		mincoor = th_min(x, y, mincoor);
		return 0;
	}
//		printf("keep random walking!\n");
	return 1;
}

int main()
{
	int count = 1;
	int particle_num;

	// put a particle in the center
	particle_set[center][center] = 1;
	maxcoor = center, mincoor = center;
	printf("%d, %d\n", center, center);

	// initialize the random number
	srand( (unsigned) time(NULL) );

	fprintf(stderr, "Please input how many particle you want(Positive integer): ");
	scanf("%d", &particle_num);


	while (count<particle_num && mincoor-2*DIST>0 && maxcoor+2*DIST<RANGE)
    {
		int x=0, y=0;
		new_particle(&x, &y);
		while(aggregate_or_escape(x,y,particle_set, &count))
		{
			random_walk(&x, &y);
		}
	}

	fprintf(stderr, "Totally %d particles!\n", count);
	return 0;
}
