/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeyun <yeyun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 09:07:47 by yeyun             #+#    #+#             */
/*   Updated: 2022/02/05 11:19:57 by yeyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	g_top_left_p = '/', g_top_right_p = '\\';
char	g_top_bottom_line = '*';
char	g_bottom_left_p = '\\', g_bottom_right_p = '/';
char	g_left_right_line = '*';
char	g_space = ' ';

void	ft_putchar(char ch);

void	print_line(int width, char left_point, char line, char right_point)
{
	int	w_index;

	w_index = 0;
	while (w_index < width)
	{
		if (w_index == 0)
		{
			ft_putchar(left_point);
		}
		else if (w_index == width - 1)
		{
			ft_putchar(right_point);
		}
		else
		{
			ft_putchar(line);
		}
		w_index++;
	}
	ft_putchar('\n');
}

void	print_row(int h_index, int height, int width)
{
	if (h_index == 0)
	{
		print_line(width, g_top_left_p, g_top_bottom_line, g_top_right_p);
	}
	else if (h_index == height - 1)
	{
		print_line(width, g_bottom_left_p, g_top_bottom_line, g_bottom_right_p);
	}
	else
	{
		print_line(width, g_left_right_line, g_space, g_left_right_line);
	}
}

void	rush(int width, int height)
{
	int	h_index;

	if (width <= 0 || height <= 0)
	{
		return ;
	}
	h_index = 0;
	while (h_index < height)
	{
		print_row(h_index, height, width);
		h_index++;
	}
}
