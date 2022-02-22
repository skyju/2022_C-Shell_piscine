/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:29:03 by yunhchoi          #+#    #+#             */
/*   Updated: 2022/02/22 10:56:05 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdio.h>

void	clear_set(char *set)
{
	int	i;

	i = -1;
	while (++i < 3)
		set[i] = ' ';
}

void	print_value(int j, char *set, int digit)
{
	if (j != 0 && ft_atoi(set))
		ft_print(" ");
	if (ft_atoi(set))
		ft_print(g_result[ft_atoi(set)]);
	if (digit && ft_atoi(set) != 0)
	{
		ft_print(" ");
		ft_print(get_digit(digit));
	}
}

int	parse_print(int digit, int offset, char *set, char *str)
{
	int	i;
	int	j;

	j = 0;
	if (digit == 1 && str[0] == '0')
	{
		ft_print(g_result[0]);
		digit = 0;
	}
	while (digit--)
	{
		clear_set(set);
		i = offset;
		if (offset != 3)
			offset = 3;
		ft_memcpy(&set[3 - i], &str[j], i);
		if (!g_result[ft_atoi(set)])
			return (-1);
		print_value(j, set, digit);
		j += i;
	}
	ft_print("\n");
	return (1);
}

int	parsing(char *str)
{
	int		len;
	int		digit;
	int		offset;
	char	set[4];

	len = ft_strlen(str);
	offset = len % 3;
	digit = len / 3 + 1;
	if (validate_node(digit, offset, set, str) == -1)
		return (-1);
	return (parse_print(digit, offset, set, str));
}

int	main(int ac, char **av)
{
	char	*dict;
	int		idx;
	int		ret;

	idx = 1;
	ret = 0;
	dict = NULL;
	if (ac == 3)
	{
		idx = 2;
		dict = av[1];
	}
	else if (ac == 2)
		dict = "numbers.dict";
	ret = (ac == 1 || ac > 3 || validate_input(av[idx]) == -1);
	if (!ret)
		ret = (init_dict(dict) == -1 || parsing(av[idx]) == -1) * 2;
	if (ret == 1)
		write(2, "Error\n", 6);
	if (ret == 2)
		write(2, "Dict Error\n", 11);
	free_all();
	return (ret);
}
