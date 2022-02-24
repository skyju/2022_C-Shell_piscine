/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_alpha.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 14:40:53 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/24 14:51:02 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_low_alphabet(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

void	ft_repeat(char *str)
{
	int	i;
	int	repeat;

	i = 0;
	while (str[i])
	{
		if (is_low_alphabet(str[i]))
		{
			repeat = str[i] - 96;
			while (repeat--)
				write(1, &str[i], 1);
		}
		else
			write(1, &str[i], 1);
		++i;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		ft_repeat(argv[1]);
	write(1, "\n", 1);
	return (0);
}
