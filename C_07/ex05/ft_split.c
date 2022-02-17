/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:17:20 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/17 11:40:45 by mkwak            ###   ########.fr       */
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

int	ft_count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 1;
	while (str[i] != '\0')
	{
		if (ft_is_charset(str[i], charset)
			&& !ft_is_charset(str[i + 1], charset))
			++count;
		++i;
	}
	return (count);
}

char	*ft_make_str(char *str, char *charset)
{
	int		str_len;
	int		i;
	char	*new_str;

	str_len = 0;
	while (*(str + str_len) && !ft_is_charset(str[str_len], charset))
		++str_len;
	new_str = (char *)malloc(str_len * sizeof(char) + 1);
	i = 0;
	while (i < str_len)
	{
		new_str[i] = str[i];
		++i;
	}
	new_str[i] = 0;
	return (new_str);
}

char	**ft_split(char *str, char *charset)
{
	char	**str_arr;
	int		arr_i;
	int		i;
	int		word_num;

	word_num = ft_count_words(str, charset);
	str_arr = (char **)malloc((word_num + 1) * sizeof(char *));
	arr_i = 0;
	i = 0;
	while (*(str + i))
	{
		while (*(str + i) && ft_is_charset(*(str + i), charset))
			++i;
		if (*(str + i) && !ft_is_charset(*(str + i), charset))
		{
			str_arr[arr_i] = ft_make_str((str + i), charset);
			++arr_i;
		}
		while (*(str + i) && !ft_is_charset(*(str + i), charset))
			++i;
	}
	str_arr[arr_i] = 0;
	return (str_arr);
}
