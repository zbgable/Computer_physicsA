
// random walk function
int random_walk(int *x, int *y)
{
    int seed=Seed();
    seed=Schrage(seed);//#rand
	int num = seed%4;
	switch(num)
	{
		case 0:
			(*x)++;
			break;
		case 1:
			(*y)++;
			break;
		case 2:
			(*x)--;
			break;
		case 3:
			(*y)--;
			break;
	}
//	printf("num=%d, x=%d, y=%d\n", num, *x, *y);
	return 0;
}
