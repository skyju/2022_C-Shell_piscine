/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:17:20 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/17 14:43:55 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft__strlen(char *src)
{
	int	count;

	count = 0;
	while (src[count])
		++count;
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_len;

	i = 0;
	dest_len = ft__strlen(dest);
	while (*(src + i))
	{
		*(dest + dest_len + i) = *(src + i);
		++ i;
	}
	*(dest + dest_len + i) = '\0';
	return (dest);
}

int	ft_malloc_size_cal(int size, char **strs, char *sep)
{
	int	str_len;
	int	sep_len;
	int	i;

	str_len = 0;
	sep_len = ft__strlen(sep);
	i = 0;
	if (size == 1)
		return (ft__strlen(strs[0]) + 1);
	while (i < size - 1)
	{
		str_len += ft__strlen(strs[i]);
		str_len += sep_len;
		++i;
	}
	str_len += ft__strlen(strs[i]);
	return (str_len + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_length;
	int		i;
	char	*str;

	if (size == 0)
	{
		str = (char *)malloc(1);
		str[0] = 0;
		return (str);
	}
	total_length = ft_malloc_size_cal(size, strs, sep);
	str = (char *)malloc(total_length * sizeof(char));
	if (str == 0)
		return (0);
	if (*str != 0)
		*str = 0;
	i = 0;
	while (i < (size - 1))
	{
		str = ft_strcat(str, *(strs + i));
		str = ft_strcat(str, sep);
		++i;
	}
	str = ft_strcat(str, *(strs + i));
	return (str);
}
