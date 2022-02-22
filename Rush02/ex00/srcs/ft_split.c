/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhchoi <yunhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:28:32 by yunhchoi          #+#    #+#             */
/*   Updated: 2022/02/20 16:45:23 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_strncpy(char *dst, char *src, int len)
{
	while (*src && len--)
		*dst++ = *src++;
	*dst = '\0';
}

int	is_seperator(char s, char c)
{
	return (c == s);
}

int	count_words(char *str, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (is_seperator(str[i], c))
		{
			i++;
			continue ;
		}
		words++;
		while (str[i] && !is_seperator(str[i], c))
			i++;
	}
	return (words);
}

char	**split_words(char *str, char c, char **dst)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	j = 0;
	while (str[j])
	{
		while (is_seperator(str[j], c))
			j++;
		size = 0;
		if (!str[j])
			break ;
		while (str[j + size] && !is_seperator(str[j + size], c))
			size++;
		dst[i] = (char *)malloc(sizeof(char) * (size + 1));
		if (!dst[i])
			return (NULL);
		ft_strncpy(dst[i], &str[j], size);
		j += size;
		i++;
		if (!str[j])
			break ;
	}
	return (dst);
}

char	**ft_split(char *str, char sep)
{
	char	**dst;

	if (str == NULL)
		return (NULL);
	dst = (char **)malloc(sizeof(char *) * (count_words(str, sep) + 1));
	if (!dst)
		return (NULL);
	dst[count_words(str, sep)] = 0;
	return (split_words(str, sep, dst));
}
