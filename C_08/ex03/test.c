#include "ft_point.h"
#include <stdio.h>

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int	main(void)
{
	t_point	point;
	t_point *pointer;
	pointer = &point;
	set_point(&point);
	printf("%d, %d\n", (pointer->x), (pointer->y));
	return (0);
}