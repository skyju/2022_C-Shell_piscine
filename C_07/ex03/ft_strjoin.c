/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:17:20 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/15 20:44:51 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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
	int	dest_length;

	i = 0;
	dest_length = ft__strlen(dest);
	while (*(src + i))
	{
		*(dest + dest_length + i) = *(src + i);
		++ i;
	}
	*(dest + dest_length + i) = '\0';
	return (dest);
}

int	ft_malloc_size_cal(int size, char **strs, char *sep)
{
	int	result_length;
	int	sep_length;
	int	index;

	result_length = 0;
	sep_length = ft__strlen(sep);
	index = 0;
	if (size == 1)
		return (ft__strlen(strs[0]) + 1);
	while (index < size - 1)
	{
		result_length += ft__strlen(strs[index]);
		result_length += sep_length;
		++index;
	}
	result_length += ft__strlen(strs[index]);
	return result_length + 1;
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		total_length;
	int		i;
	char	*to_return;

	if (size == 0)
		return ((char *)malloc(sizeof(char)));
	total_length = ft_malloc_size_cal(size, strs, sep);
	printf("[ malloc size는 %d ]\n", total_length);
	to_return = (char *)malloc(total_length * sizeof(char));
	i = 0;
	while (i < (size - 1))
	{
		to_return = ft_strcat(to_return, *(strs + i));
		to_return = ft_strcat(to_return, sep);
		++i;
	}
	to_return = ft_strcat(to_return, *(strs + i));
	return (to_return);
}
