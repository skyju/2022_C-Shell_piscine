/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_and_replace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:36:01 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/24 17:54:29 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(char *str, char to_find, char niddle)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_find)
			write(1, &niddle, 1);
		else
			write(1, &str[i], 1);
		++i;
	}
	return ;
}

int	main(int argc, char **argv)
{
	if (argc == 4 && argv[2][1] == 0 && argv[3][1] == 0)
		ft_print(argv[1], argv[2][0], argv[3][0]);
	write(1, "\n", 1);
	return (0);
}
