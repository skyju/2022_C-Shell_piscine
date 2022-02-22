/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:12:15 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/22 18:48:13 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		++i;
	}
}

void	ft_putnbr(int nbr)
{
	if (nbr < 0)
	{
		ft_putstr("-");
		nbr *= -1;
	}
	if (nbr / 10 != 0)
		ft_putnbr(nbr / 10);
	else
	{
		ft_putchar((nbr + '0'));
		return ;
	}
	ft_putnbr(nbr % 10);
}
