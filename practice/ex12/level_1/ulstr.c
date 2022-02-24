/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulstr.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:56:00 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/24 18:02:37 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_ulstr(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			c = str[i] - ('a' - 'A');
			write(1, &c, 1);
		}
		else if ( str[i] >= 'A' && str[i] <= 'Z')
		{
			c = str[i] + ('a' - 'A');
			write(1, &c, 1);
		}
		else
			write(1, &str[i], 1);
		++i;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_ulstr(argv[1]);
	write(1, "\n", 1);
}
