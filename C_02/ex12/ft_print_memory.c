/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 21:09:40 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/17 21:35:38 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

void	ft_print_hex_num(unsigned long long add)
{
	char	*hex_arr;
	char	result_arr[16];
	int		i;

	hex_arr = "0123456789abcdef";
	i = 15;
	while (i >= 0)
	{
		result_arr[i] = hex_arr[add % 16];
		add /= 16;
		--i;
	}
	write(1, result_arr, 16);
	write(1, ": ", 2);
}

void	ft_print_hex_char(char *add, unsigned int size)
{
	char			*hex_arr;
	char			result_arr[32];
	unsigned char	c;
	unsigned int	i;

	hex_arr = "0123456789abcdef";
	i = 0;
	while (i < size)
	{
		c = (unsigned char)add[i];
		result_arr[i * 2] = hex_arr[c / 16];
		result_arr[i * 2 + 1] = hex_arr[c % 16];
		++i;
	}
	i = 0;
	while (i < 32)
	{
		if (i < size * 2)
			write(1, &result_arr[i], 1);
		else
			write(1, " ", 1);
		if (i % 4 == 3)
			write(1, " ", 1);
		++i;
	}
}

void	ft_print_str(char *str, unsigned int size)
{
	char			result_arr[16];
	unsigned int	i;

	i = 0;
	while (i < size)
	{
		if (str[i] < ' ' || str[i] > 126)
			result_arr[i] = '.';
		else
			result_arr[i] = str[i];
		i++;
	}
	result_arr[16] = 0;
	write(1, result_arr, size);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int		i;
	unsigned long long	addr_num;
	char				*addr_str;

	addr_str = (char *)addr;
	addr_num = (unsigned long long)addr;
	i = 0;
	while (i < size)
	{
		ft_print_hex_num(addr_num + i);
		if (size - i > 15)
		{
			ft_print_hex_char(addr_str + i, 16);
			ft_print_str(addr_str + i, 16);
		}
		else
		{
			ft_print_hex_char(addr_str + i, size - i);
			ft_print_str(addr_str + i, size - i);
		}
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}
