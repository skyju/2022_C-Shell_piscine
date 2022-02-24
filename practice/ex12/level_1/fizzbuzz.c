#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;
	
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		++i;
	}
}

void	ft_positive_putnbr(int nb)
{
	char	c;
	if (nb / 10 != 0)
		ft_positive_putnbr(nb / 10);
	else
	{
		c = nb + '0';
		write(1, &c, 1);
		return ;
	}
	ft_positive_putnbr(nb % 10);
}

int	main(void)
{
	int		i;

	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0)
			ft_putstr("fizz");
		else if (i % 5 == 0)
			ft_putstr("buzz");
		else
			ft_positive_putnbr(i);
		write(1, "\n", 1);
		++i;
	}
	return (0);
}
