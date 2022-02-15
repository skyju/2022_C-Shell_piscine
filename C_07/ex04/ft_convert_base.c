/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:17:20 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/15 16:50:43 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_white_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t'
		|| c == '\r' || c == '\v' || c == '\f')
		return 1;
	return 0;
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

int	ft_base_checking(char *base)
{
	int	i;

	i = 0;
	if (base[0] == 0 || base [1] == 0)
		return (-1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || ft_is_white_space(base[i]))
			return (-1);
		if (ft_my_strstr((base + i + 1), base[i]))
			return (-1);
		++i;
		
	}
	return (i);
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
	int	i;
	int	minus;
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

int	ft_cal_malloc_size(long long nbr, int obase)
{
	int cnt;

	cnt = 0;
	while (nbr >= obase)
	{
		nbr /= obase;
		++cnt;
	}
	return (++cnt);
}

int	ft_itoa_base(int nbr, char *base_to, char *res, int i, int obase)
{
	long long	n;

	n = nbr;
	if (nbr < 0)
	{
		*res = '-';
		n *= -1;
		++i;
	}
	if (n / obase != 0)
		ft_itoa_base(n / obase, base_to, res, --i, obase);
	res[i] = base_to[n % obase];
	return (i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			ibase;
	int			obase;
	long long	after_atoi;
	char		*res;
	int			last_i;
	int			malloc_size;

	ibase = ft_base_checking(base_from);
	obase = ft_base_checking(base_to);
	if(ibase <= 1 || obase <= 1)
		return (0);
	after_atoi = ft_atoi_base(nbr, ibase, base_from);
	malloc_size = ft_cal_malloc_size(after_atoi, obase);
	res = (char *)malloc(malloc_size * sizeof(char));
	last_i = ft_itoa_base(after_atoi, base_to, res, malloc_size, obase);
	res[last_i + 1] = '\0';
	return (res);
}