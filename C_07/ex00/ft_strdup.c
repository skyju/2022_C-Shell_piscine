/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:17:20 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/14 10:33:26 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *src)
{
	int	count;

	count = 0;
	while (src[count] != '\0')
		++count;
	return (count);
}

char	*ft_strdup(char *src)
{
	char	*t;
	int		src_length;
	int		i;

	src_length = ft_strlen(src);
	t = (char *)malloc(src_length + 1 * sizeof(char));
	while (src[i] != '\0')
	{
		t[i] = src[i];
		++i;
	}
	t[i] = '\0';
	return (t);
}
