/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:50:12 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/21 18:07:50 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int ft_any(char **tab, int(*f)(char*))
{
	int	i;
	int	result;

	i = 0;
	while (*(tab + i) != 0)
	{
		result = (*f)(*(tab + i));
		if (result != 0)
			return (1);
		++i;
	}
	return (0);
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
	printf("\n--ex02--\n");
	char *strs[5];
	strs[0] = " 01823948\t";
	strs[1] = "abeemkdAS";
	strs[2] = "102984";
	strs[3] = "123asf";
	strs[4] = 0;
	printf("1 : %d\n", ft_any(strs, &only_digit));
	strs[2] = "[]po[]";
	printf("0 : %d\n", ft_any(strs, &only_digit));
}
