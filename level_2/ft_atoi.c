/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:03:40 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/24 18:18:48 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_white_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	sign;

	i = 0;
	result = 0;
	while (is_white_space(str[i]))
		++i;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
	{
		sign = 1;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		++i;
	}
	result *= sign;
	return (result);
}

int	main(void)
{
	printf("%d\n", ft_atoi("    \n\n\n\t -2147483548asdfasddf"));
	return (0);
}
