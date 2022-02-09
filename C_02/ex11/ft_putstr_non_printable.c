/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:13:10 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/09 20:10:30 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int				i;
	char			*hexadecimal_array;
	unsigned char	protect_minus_ascii_temp;
	unsigned char	sixteen_multiply_zero;
	unsigned char	sixteen_multiply_one;

	hexadecimal_array = "0123456789abcdef";
	i = 0;
	while (*(str + i))
	{
		if (*(str + i) < 32 || *(str + i) > 126)
		{
			protect_minus_ascii_temp = *(str + i);
			sixteen_multiply_zero = protect_minus_ascii_temp / 16;
			sixteen_multiply_one = protect_minus_ascii_temp % 16;
			write(1, "\\", 1);
			write(1, hexadecimal_array + sixteen_multiply_zero, 1);
			write(1, hexadecimal_array + sixteen_multiply_one, 1);
		}
		else
			write(1, (str + i), 1);
		++i;
	}
}
