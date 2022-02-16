/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:17:20 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/16 21:37:36 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		++i;
	}
	return (0);
}

int	ft_full_malloc_size(char *str, char *charset)
{
	int	i;
	int	malloc_size;

	i = 0;
	malloc_size = 1;
	while (*(str + i))
	{
		while (*(str + i) && ft_is_charset(str[i], charset))
			++i;
		while (*(str + i) && !ft_is_charset(str[i], charset))
		{
			++i;
			++malloc_size;
		}
		if (*(str + i) && ft_is_charset(str[i], charset))
			++malloc_size;
	}
	return (malloc_size);
}

char	*ft_make_str(char *str, char *charset)
{
	int		i;
	int		j;
	char	*to_return;

	i = 0;
	while (*(str + i) && !ft_is_charset(str[i], charset))
		++i;
	to_return = (char *)malloc(i * sizeof(char) + 1);
	printf ("한 단어 배열 사이즈: %d\n", i+1);
	j = 0;
	while (j < i)
	{
		to_return[j] = str[j];
		++j;
	}
	to_return[j] = '\0';
	return (to_return);
}

char	**ft_split(char *str, char *charset)
{
	char	**to_return;
	int		to_return_i;

	to_return = (char **)
		malloc(ft_full_malloc_size(str, charset) + 1 * sizeof(char));

	printf("총 return size: %d\n", ft_full_malloc_size(str, charset)+1);
	
	to_return_i = 0;
	while (*str)
	{
		while (*str && ft_is_charset(*str, charset))
			++str;
		if (*str && !ft_is_charset(*str, charset))
		{
			to_return[to_return_i] = ft_make_str(str, charset);
			++to_return_i;
		}
		while (*str && !ft_is_charset(*str, charset))
			++str;
	}
	*(to_return + to_return_i) = 0;
	return (to_return);
}
