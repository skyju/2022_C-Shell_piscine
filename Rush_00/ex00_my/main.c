#include <time.h>
#include <stdio.h>
void	rush(int a, int b);

int	main(void)
{
	double start, end;
	start = (double)clock() / CLOCKS_PER_SEC;
	rush(10000, 5000);
	end = (((double)clock()) / CLOCKS_PER_SEC);
	printf("시간 : %lf\n", (end - start));
	return (0);
}