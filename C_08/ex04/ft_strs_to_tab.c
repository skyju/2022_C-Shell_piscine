/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 13:43:35 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/19 17:41:57 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		++i;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*result;
	int		i;

	i = 0;
	while (str[i])
		++i;
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		result[i] = str[i];
		++i;
	}
	result[i] = '\0';
	return (result);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str *result;
	int	i;
	
	result = (struct s_stock_str *)malloc(sizeof(struct s_stock_str) * ac);
	(void)ac;
	i = 0;
	while (av[i] != 0)
	{
		(result + i)->size = ft_strlen(av[i]);
		(result + i)->str = av[i];
		(result + i)->copy = ft_strdup(av[i]);
		++i;
	}
	(result + i)->str = 0;
	return (result);
}