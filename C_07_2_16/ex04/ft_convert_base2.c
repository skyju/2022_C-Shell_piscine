/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:17:20 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/16 12:58:43 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_white_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_my_strstr(char *haystack, char niddle)
{
	int	i;

	i = 0;
	while (*(haystack + i))
	{
		if (*(haystack + i) == niddle)
			return (1);
		++i;
	}
	return (0);
}

int	ft_base_indexing(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		++i;
	}
	return (-1);
}

long long	ft_atoi_base(char *nbr, int ibase, char *base_from)
{
	int			i;
	int			minus;
	long long	result;

	i = 0;
	minus = 0;
	result = 0;
	while (ft_is_white_space(nbr[i]))
		++i;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			++minus;
		++i;
	}
	while (ft_base_indexing(nbr[i], base_from) != -1)
	{
		result *= ibase;
		result += ft_base_indexing(nbr[i], base_from);
		++i;
	}
	if (minus % 2 == 1)
		result *= -1;
	return (result);
}
