#include "ft_strs_to_tab.c"
#include "../ex05/ft_show_tab.c"

int	main(int ac, char **av)
{
	struct s_stock_str *result;
	result = ft_strs_to_tab(ac, av);
	ft_show_tab(result);
}