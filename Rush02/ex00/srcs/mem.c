/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taekwlee <taekwlee@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:25:22 by taekwlee          #+#    #+#             */
/*   Updated: 2022/02/20 17:27:32 by taekwlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_memcpy(void *dst, void *src, unsigned int len)
{
	char			*to;
	char			*from;
	unsigned int	i;

	to = (char *)dst;
	from = (char *)src;
	i = 0;
	while (i < len)
	{
		to[i] = from[i];
		i++;
	}
}

void	free_list(t_dict **list)
{
	int	i;

	i = -1;
	if (!list)
		return ;
	while (list[++i])
	{
		free(list[i]->key);
		free(list[i]->value);
		free(list[i]);
	}
	free(list);
}

void	free_words(char **strs)
{
	int	i;

	if (!strs)
		return ;
	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

void	free_all(void)
{
	free_list(g_number_dict);
	free_list(g_digit_dict);
	free_words(g_result);
}
