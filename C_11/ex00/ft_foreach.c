/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:29:52 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/21 18:03:29 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_foreach(int *tab, int length, void(*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		(*f)(tab[i]);
		++i;
	}
}

void print_int(int a)
{
	printf("%d\n", a);
}

int	main(void)
{
	printf("--ex00--\n");
	int arr[10] = {1, 2, 9, 8, 3, 4, 6, 5, 0, 0};
	for(int i=0;i<10;i++)
		printf("%d ", arr[i]);
	printf(":\n");
	ft_foreach(arr, 10, &print_int);
	printf("\n");
}
