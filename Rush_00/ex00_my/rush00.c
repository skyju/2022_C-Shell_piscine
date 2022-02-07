char	g_left_top = 'o';
char	g_right_top = 'o';
char	g_left_bottom = 'o';
char	g_right_bottom = 'o';
char	g_left_right_side = '|';
char	g_top_bottom_side = '-';

void	ft_putchar(char c);

void	my_print(int row, int col, int col_max, int row_max)
{
	if (row == 1 && col == 1)
		ft_putchar(g_left_top);
	else if (row == 1 && col == col_max)
		ft_putchar(g_right_top);
	else if (row == row_max && col == 1)
		ft_putchar(g_left_bottom);
	else if (row == row_max && col == col_max)
		ft_putchar(g_right_bottom);
	else if (col == 1 || col == col_max)
		ft_putchar(g_left_right_side);
	else if (row == 1 || row == row_max)
		ft_putchar(g_top_bottom_side);
	else
		ft_putchar(' ');
}

void	rush(int col_max, int row_max)
{
	int	row;
	int	col;

	row = 1;
	if (col_max <= 0 || row_max <= 0)
		return ;
	while (row <= row_max)
	{
		col = 1;
		while (col <= col_max)
		{
			my_print(row, col, col_max, row_max);
			col++;
		}
		ft_putchar('\n');
		row++;
	}
}
