/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:08:16 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/21 18:13:03 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_count_if(char **tab, int length, int(*f)(char*))
{
	int	i;
	int	result;
	int	count;
	
	i = 0;
	count = 0;
	while (i < length)
	{
		result = (*f)(*(tab + i));
		if (result != 0)
			++count;
		++i;
	}
	return (count);
}

int	only_digit(char *str)
{
	while (*str)
	{
		if (!('0' <= *str && *str <= '9'))
			return (0);
		str++;
	}
	return (1);
}

int	main(void)
{
	printf("\n--ex03--\n");
	char *strs[5];
	strs[0] = " 01823948\t";
	strs[1] = "abeemkdAS";
	strs[2] = "102984";
	strs[3] = "123";
	strs[4] = "12annbkm12";
	printf("2 : %d\n", ft_count_if(strs, 5,  &only_digit));
	strs[2] = "[]po[]";
	printf("1 : %d\n", ft_count_if(strs, 5, &only_digit));
}
