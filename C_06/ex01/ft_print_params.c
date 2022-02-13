/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:22:48 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/12 17:35:01 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printer(char *str)
{
	int		i;

	i = 0;
	while (*(str + i))
	{
		write(1, &(*(str + i)), 1);
		++i;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int	arg_index;

	arg_index = 1;
	while (arg_index < argc)
	{
		printer(*(argv + arg_index));
		++arg_index;
	}
}
