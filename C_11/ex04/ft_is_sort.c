/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:12:15 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/21 19:33:42 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	j;
	int	result;
	int	temp;
	int	temp2;
	int	flag;

	i = 0;
	flag = 0;
	while (i < length - 1)
	{
		j = i + 1;
		while (j < length - 2)
		{
			temp = *(tab + i);
			temp2 = *(tab + j);
			result = (*f)(temp, temp2);
			if (flag > 0 && result < 0)
				return (0);
			flag = result;
			++j;
		}
		++i;
	}
	return (1);
}

int return_min(int a, int b)
{
	return (a - b);
}

int	main(void)
{
	printf("\n--ex04--\n");
	int arr1[10] = {1, 2, 9, 8, 3, 4, 6, 5, 10, 11};
	for(int i=0;i<10;i++)
		printf("%d ", arr1[i]);
	printf(": %d\n", ft_is_sort(arr1, 10, &return_min));
	int arr2[10] = {-10, 2, 3, 4, 5, 6, 7, 8, 10, 112};
	for(int i=0;i<10;i++)
		printf("%d ", arr2[i]);
	printf(": %d\n", ft_is_sort(arr2, 10, &return_min));
	int arr3[10] = {11, 9, 6, 3, 1, 0, -1, -13, -14, -15};
	for(int i=0;i<10;i++)
		printf("%d ", arr3[i]);
	printf(": %d\n", ft_is_sort(arr3, 10, &return_min));
}
