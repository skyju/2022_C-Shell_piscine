#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[i])
		{
			if (argv[i][1] == 'a')
			{
				write(1, "a\n", 2);
				return (0);
			}
			++i;
		}
	}
	write(1, "a\n", 2);
	return (0);
}