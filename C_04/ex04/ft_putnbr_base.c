/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:37:45 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/10 21:43:06 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_length(char *str)
{
	int	count;
	
	count = 0;
	while(*(str + count))
		++count;
	return (count);
}

int ft_my_strstr(char *str, char to_find)
{
	int	index;

	while (*str)
	{	
		index = 0;
		while (*(str + index) == to_find)
			return (1);
		++str;
	}
	return (0);
}

int ft_str_checking(char *str)
{
	int		check;
	int		index;
	
	index = 0;
	check = 0;
	while (*(str + index))
	{
		if (*(str + index) == '-' || *(str + index) == '+')
			check = 1;
		if (ft_my_strstr((str + index + 1), *(str + index)))
			check = 1;
		++index;
	}
	return check;
}

void	ft_printer_for_base(int nbr, int obase)
{	
	char	temp;
	
	if (nbr / obase != 0)
		ft_printer_for_base(nbr / obase, obase);
	else
	{
		temp = nbr + '0';
		if (temp > '9')
			temp += 39;
		write(1, &temp, 1);
		return ;
	}
	ft_printer_for_base(nbr % obase, obase);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		obase;
	int		check;

	obase = ft_str_length(base);
	check = ft_str_checking(base);
	if (obase == 0 || obase == 1 || check == 1)
		return ;
	if (nbr < 0)
		write(1, "-", 1);
	ft_printer_for_base(nbr, obase);
}

int main(void)
{
	ft_putnbr_base(10, "012345678");
	return 0;
}