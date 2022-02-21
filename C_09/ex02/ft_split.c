/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:15:43 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/21 16:35:55 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

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

int	ft_words_count(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i])
	{
		if (ft_is_charset(str[i], charset)
			&& !ft_is_charset(str[i + 1], charset))
			count++;
		++i;
	}
	return (count);
}

char	*ft_make_str(char *str, char *charset)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i] && !ft_is_charset(str[i], charset))
		++i;
	new_str = (char *)malloc((i + 1) * sizeof(char));
	if (new_str == 0)
		return (0);
	i = 0;
	while (str[i] && !ft_is_charset(str[i], charset))
	{
		new_str[i] = str[i];
		++i;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	**ft_split(char *str, char *charset)
{
	char	**str_arr;
	int		word_num;
	int		arr_i;
	int		i;

	word_num = ft_words_count(str, charset);
	str_arr = (char **)malloc((word_num + 1) * sizeof(char *));
	if (str_arr == 0)
		return (0);
	arr_i = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && ft_is_charset(str[i], charset))
			++i;
		if (str[i] && !ft_is_charset(str[i], charset))
		{
			str_arr[arr_i] = ft_make_str((str + i), charset);
			++arr_i;
		}
		while (str[i] && !ft_is_charset(str[i], charset))
			++i;
	}
	str_arr[word_num] = 0;
	return (str_arr);
}
