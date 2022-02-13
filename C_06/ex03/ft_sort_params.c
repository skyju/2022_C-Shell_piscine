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
#include <stdio.h>

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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((*(s1 + i) || *(s2 + i)))
	{
		if (*(s1 + i) != *(s2 + i))
			return (*(s1 + i) - *(s2 + i));
		++i;
	}
	return (0);
}

void	ft_swap(char *s1, char *s2)
{
	char	*temp;

	temp = s1;
	s1 = s2;
	s2 = temp;
}

int	main(int argc, char **argv)
{
	int i;
	int j;
	int arg_index;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc -1)
		{
			if (ft_strcmp(argv[i], argv[j]) < 0)
				ft_swap(argv[i], argv[j]);
			++j;
		}
		++i;
	}
	arg_index = 1;
	while (arg_index < argc)
	{
		printer(*(argv + arg_index));
		++arg_index;
	}
}
