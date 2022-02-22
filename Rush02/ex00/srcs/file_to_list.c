/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhchoi <yunhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:26:50 by yunhchoi          #+#    #+#             */
/*   Updated: 2022/02/20 16:32:10 by yunhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	alloc_dict(t_dict **list, int size)
{
	int	digits;
	int	i;

	digits = 0;
	i = -1;
	while (++i < size)
		digits += ft_strlen(list[i]->key) > 3;
	g_digit_dict = (t_dict **)malloc(sizeof(t_dict *) * (digits + 1));
	if (!g_digit_dict)
	{
		free_list(list);
		return (-1);
	}
	g_digit_dict[digits] = NULL;
	g_number_dict = (t_dict **)malloc(sizeof(t_dict *) * (size - digits + 1));
	if (!g_number_dict)
	{
		free(g_number_dict);
		free_list(list);
		return (-1);
	}
	g_number_dict[size - digits] = NULL;
	return (1);
}

int	split_dict(t_dict **list, int size)
{
	int	i;
	int	digits;
	int	numbers;
	int	j;

	if (alloc_dict(list, size) == -1)
		return (-1);
	digits = 0;
	numbers = 0;
	i = -1;
	while (++i < size)
	{
		if (ft_strlen(list[i]->key) > 3)
			g_digit_dict[digits++] = list[i];
		else
			g_number_dict[numbers++] = list[i];
	}
	j = 0;
	free(list);
	return (1);
}

int	parse_node(t_dict **list, char **words, int len)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (++j < len)
	{
		if (add_node(ft_split(words[j], ':'), list, i++) == -1)
		{
			free_list(list);
			free_words(words);
			return (-1);
		}
	}
	return (i);
}

int	fill_dict(char *file)
{
	t_dict	**list;
	char	**words;
	int		len;
	int		size;

	words = get_lines(file);
	if (!words)
		return (-1);
	len = count_arr(words);
	list = (t_dict **)malloc(sizeof(t_dict *) * (len + 1));
	list[len] = NULL;
	if (!list)
		return (-1);
	size = parse_node(list, words, len);
	if (size == -1)
		return (-1);
	free_words(words);
	split_dict(list, size);
	return (1);
}

int	init_dict(char *name)
{
	if (fill_dict(name) == -1)
		return (-1);
	if (fill_result() == -1)
		return (-1);
	return (1);
}
