/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:12:15 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/22 18:01:00 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_white_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\r'
		|| c == '\f' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	minus;
	int	result;

	i = 0;
	minus = 0;
	result = 0;
	while (is_white_space(str[i]))
		++i;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			++minus;
		++i;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		++i;
	}
	if (minus % 2 == 1)
		result *= -1;
	return (result);
}
