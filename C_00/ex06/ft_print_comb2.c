/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:49:56 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/05 21:20:04 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	my_print(int a1, int a2, int b1, int b2)
{	
	char	c1;
	char	c2;
	char	c3;
	char	c4;

	c1 = a1 + 48;
	c2 = a2 + 48;
	c3 = b1 + 48;
	c4 = b2 + 48;
	write(1, &c1, 1);
	write(1, &c2, 1);
	write(1, " ", 1);
	write(1, &c3, 1);
	write(1, &c4, 1);
	if ((a1 * 10) + a2 + (b1 * 10) + b2 != 98 + 99)
	{
		write(1, ",", 1);
		write(1, " ", 1);
	}
}

void	ft_print_comb2(void)
{	
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{	
		b = a + 1;
		while (b <= 99)
		{	
			my_print(a / 10, a % 10, b / 10, b % 10);
			b++;
		}
		a++;
	}
}
