/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 11:13:10 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/09 14:28:27 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	int				i;
	char			*arr;
	unsigned char	one;
	unsigned char	two;

	i = 0;
	arr = "0123456789abcdef";
	while (*(str + i) != '\0')
	{	
		if (*(str + i) < 32 || *(str + i) > 126)
		{	
			one = *(str + i) / 16;
			two = *(str + i) % 16;
			write(1, "\\", 1);
			write(1, arr + one, 1);
			write(1, arr + two, 1);
		}
		else
			write(1, (str + i), 1);
		++i;
	}
}
