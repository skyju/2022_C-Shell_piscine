/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:17:20 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/17 12:51:44 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

long long	ft_atoi_base(char *nbr, int ibase, char *base_from);

int			ft_is_white_space(char c);

int			ft_my_strstr(char *haystack, char niddle);

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

int	ft_cal_malloc_size(long long nbr, int obase)
{
	int	cnt;

	cnt = 1;
	if (nbr < 0)
	{
		nbr *= -1;
		++cnt;
	}
	while (nbr >= obase)
	{
		nbr /= obase;
		++cnt;
	}
	return (cnt);
}

void	ft_itoa_base(int nbr, char *base_to, char *result, int i)
{
	int	obase;

	obase = 0;
	while (base_to[obase])
		++obase;
	if (nbr < 0)
	{
		*result = '-';
		nbr *= -1;
	}
	if (nbr / obase != 0)
	{
		ft_itoa_base(nbr / obase, base_to, result, i - 1);
	}
	else
	{
		result[i] = base_to[nbr];
		return ;
	}
	ft_itoa_base(nbr % obase, base_to, result, i);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int			ibase;
	int			obase;
	long long	after_atoi;
	char		*result;
	int			malloc_size;

	ibase = ft_base_checking(base_from);
	obase = ft_base_checking(base_to);
	if (ibase < 0 || obase < 0)
		return (0);
	after_atoi = ft_atoi_base(nbr, ibase, base_from);
	malloc_size = ft_cal_malloc_size(after_atoi, obase);
	result = (char *)malloc((malloc_size + 1) * sizeof(char));
	ft_itoa_base(after_atoi, base_to, result, malloc_size - 1);
	result[malloc_size] = '\0';
	return (result);
}
