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

int	ft_is_promising(int chessboard[], int row_num, int col_num)
{
	int	i;

	i = 0;
	while (i < row_num)
	{
		if (col_num == chessboard[i]
			|| i - chessboard[i] == row_num - col_num
			|| i + chessboard[i] == row_num + col_num)
			return (0);
		++i;
	}
	return (1);
}

void	ft_check_node(int chessboard[], int *count, int row_num)
{
	int	col_num;
	int	index;

	if (row_num == 10)
	{
		*count += 1;
		index = -1;
		while (++index < 10)
			ft_putchar(chessboard[index] + '0');
		ft_putchar('\n');
	}
	else
	{
		col_num = 0;
		while (col_num < 10)
		{
			if (ft_is_promising(chessboard, row_num, col_num))
			{
				chessboard[row_num] = col_num;
				ft_check_node(chessboard, count, row_num + 1);
			}
			++col_num;
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		chessboard[10];
	int		row_num;
	int		count;

	row_num = 0;
	count = 0;
	ft_check_node(chessboard, &count, row_num);
	return (count);
}
