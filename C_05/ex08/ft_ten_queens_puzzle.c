/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:28:36 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/15 19:28:37 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_possibility(int table[10], int x, int y)
{
	int	i;

	i = -1;
	while (++i < x)
		if (y == table[i] || i - table[i] == x - y || i + table[i] == x + y)
			return (0);
	return (1);
}

void	ft_solve(int table[10], int *result, int row)
{
	int	col;
	int	res;

	if (row == 10)
	{
		*result += 1;
		res = -1;
		while (++res < 10)
			ft_putchar(table[res] + '0');
		ft_putchar('\n');
	}
	else
	{
		col = -1;
		while (++col < 10)
		{
			if (ft_possibility(table, row, col))
			{
				table[row] = col;
				ft_solve(table, result, row + 1);
			}
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		table[10];
	int		row;
	int		result;

	row = 0;
	while (row < 10)
	{
		table[row] = -1;
		++row;
	}
	row = 0;
	result = 0;
	ft_solve(table, &result, row);
	return (result);
}
