/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_fnc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhchoi <yunhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:29:43 by yunhchoi          #+#    #+#             */
/*   Updated: 2022/02/20 16:29:52 by yunhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_print(char *str)
{
	if (!str)
		return ;
	while (*str)
		write(1, str++, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*rstrip(char *word)
{
	char	*dst;
	int		i;
	int		j;

	if (!word)
		return (NULL);
	i = 0;
	j = ft_strlen(word) - 1;
	while (word[j] == ' ')
		j--;
	dst = (char *)malloc(sizeof(char) * (j + 2));
	if (dst)
	{
		dst[j + 2] = '\0';
		ft_memcpy(dst, &word[i], j + 1);
	}
	return (dst);
}

char	*lstrip(char *word)
{
	char	*dst;
	int		j;
	int		i;

	if (!word)
		return (NULL);
	i = 0;
	while (word[i] == ' ')
		i++;
	j = ft_strlen(word);
	if (!i)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * (j - i + 1));
	if (!dst)
		return (NULL);
	dst[j - i] = '\0';
	ft_memcpy(dst, &word[i], j - i);
	return (dst);
}

int	count_arr(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}
