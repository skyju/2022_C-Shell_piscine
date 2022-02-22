/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:26:56 by yunhchoi          #+#    #+#             */
/*   Updated: 2022/02/22 10:41:26 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"
#include <stdio.h>

t_dict	*creat_node(char *key, char *val)
{
	t_dict	*node;

	node = (t_dict *)malloc(sizeof(t_dict));
	if (!node)
		return (NULL);
	node->key = key;
	node->value = val;
	return (node);
}

int	add_node(char **words, t_dict **list, int idx)
{
	if (validate_dict(words) == -1)
		return (-1);
	list[idx] = creat_node(rstrip(words[0]), lstrip(words[1]));
	if (!list[idx] || !list[idx]->key || !list[idx]->value)
		return (-1);
	if (ft_strlen(list[idx]->key) <= 3)
		list[idx]->num = ft_atoi(list[idx]->key);
	else
	{
		if (validate_digit(list[idx]->key) != -1)
			list[idx]->digit = ft_strlen(list[idx]->key) / 3;
	}
	free_words(words);
	return (1);
}

char	*get_digit(int digit)
{
	int	i;

	i = -1;
	while (g_digit_dict[++i])
	{
		if (g_digit_dict[i]->digit == digit)
			return (g_digit_dict[i]->value);
	}
	return (NULL);
}
