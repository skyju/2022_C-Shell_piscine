/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:37:45 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/12 18:31:47 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_my_strstr(char *str, char to_find)
{
	while (*str)
	{	
		if (*(str) == to_find)
			return (1);
		++str;
	}
	return (0);
}

int	ft_base_checking(char *base)
{
	int		check;
	int		index;

	index = 0;
	check = 0;
	while (*(base + index))
	{
		if (*(base + index) == '-' || *(base + index) == '+')
			check = 1;
		if (ft_my_strstr((base + index + 1), *(base + index)))
			check = 1;
		++index;
	}
	return (check);
}

void	ft_printer_for_base(long long n, int obase, char *base)
{	
	char	temp;

	if (n / obase != 0)
		ft_printer_for_base(n / obase, obase, base);
	else
	{
		temp = *(base + n);
		write(1, &temp, 1);
		return ;
	}
	ft_printer_for_base(n % obase, obase, base);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			obase;
	int			check;
	long long	n;

	obase = 0;
	while (*(base + obase))
		++obase;
	check = ft_base_checking(base);
	n = nbr;
	if (obase == 0 || obase == 1 || check == 1)
		return ;
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	ft_printer_for_base(n, obase, base);
}

int main()
{
	{
		printf("----ex04----\n");
		printf("8867\n");
		ft_putnbr_base(1132, "9876543210");
		printf("\n");

		printf("[SHOULD NOT PRINT]\n");
		ft_putnbr_base(1132, "");
		printf("\n");

		printf("[SHOULD NOT PRINT]\n");
		ft_putnbr_base(1132, "aabc!");
		printf("\n");

		printf("-bDBbFjci\n");
		ft_putnbr_base(-2147483648, "abcdefghijABCDEFGHIJ"); // 20base
		printf("\n");

		printf("*///////\n");
		ft_putnbr_base(2147483647, "!@#$%^&*()<>,.?/"); // 16base
		printf("\n");

		printf("-@@#!\n");
		ft_putnbr_base(-42, "!@#"); // 3base
		printf("\n");
	}
	printf("\n");
}