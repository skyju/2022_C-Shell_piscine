/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:48:12 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/21 18:01:39 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*to_return;

	to_return = (int *)malloc(sizeof(int) * length);
	if (!to_return)
		return (0);
	i = 0;
	while (i < length)
	{
		*(to_return + i) = (*f)(tab[i]);
		++i;
	}
	return (to_return);
}

int	plus_3(int a)
{
	return (a + 3);
}

int	main(void)
{
	printf("\n--ex01--\n");
	int arr[10] = {1, 2, 9, 8, 3, 4, 6, 5, 0, 4};
	for(int i=0;i<10;i++)
		printf("%d ", arr[i]);
	printf(": ");
	int *return_arr = ft_map(arr, 10, &plus_3);
	for(int i=0;i<10;i++)
		printf("%d ", return_arr[i]);
	free(return_arr);
	printf("\n");
}
