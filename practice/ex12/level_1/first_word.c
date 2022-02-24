#include <unistd.h>

int	is_sep(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	ft_printer(char *str)
{
	int i;

	i = 0;
	while (!is_sep(str[i]) && str[i] != '\0')
	{
		write(1, &str[i], 1);
		++i;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 1)
		ft_printer(argv[1]);
	write(1, "\n", 1);
	return (0);
}
