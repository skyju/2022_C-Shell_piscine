/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_result2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:27:20 by yunhchoi          #+#    #+#             */
/*   Updated: 2022/02/22 10:30:05 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdio.h>

int	fill_2num(void)
{
	int		i;
	char	*n1_str;
	char	*n2_str;

	i = 20;
	while (++i < 100)
	{
		if (i % 10 != 0)
		{
			n2_str = g_result[i % 10];
			n1_str = g_result[i - (i % 10)];
			g_result[i] = NULL;
			if (!n2_str || !n1_str)
				continue ;
			g_result[i] = malloc_dict(n1_str, n2_str, 0);
			ft_strcat(g_result[i], n1_str);
			ft_strcat(g_result[i], n2_str);
		}
	}
	return (0);
}

int	fill_3num(void)
{
	int		i;
	char	*n1_str;
	char	*n2_str;
	char	*n3_str;

	i = 100;
	while (++i < 1000)
	{
		n1_str = g_result[i / 100];
		n2_str = g_result[100];
		n3_str = g_result[i % 100];
		if (!n1_str || !n2_str || !n3_str)
			continue ;
		if (i % 100 == 0)
			n3_str = 0;
		g_result[i] = NULL;
		g_result[i] = malloc_dict(n1_str, n2_str, n3_str);
		ft_strcat(g_result[i], n1_str);
		ft_strcat(g_result[i], n2_str);
		ft_strcat(g_result[i], n3_str);
	}
	return (0);
}
