/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 20:05:24 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/22 20:26:49 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		++i;
	}
}

int	main(int argc, char **argv)
{
	char	dst[4096];
	int		fd;

	if (argc == 1)
		write(2, "File name missing.", 18);
	else if (argc > 2)
		write(2, "Too many arguments.", 19);
	else
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (0);
		dst[4095] = '\0';
		if (read(fd, dst, 4096) < 0)
		{
			*dst = 0;
			write(2, "Cannot read file.", 17);
		}
		if (fd >= 3)
			close(fd);
		ft_putstr(dst);
	}
	return (0);
}
