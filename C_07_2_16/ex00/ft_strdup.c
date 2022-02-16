/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:17:20 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/14 16:17:54 by mkwak            ###   ########.fr       */
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
	char	*new_src;
	int		src_length;
	int		i;

	src_length = ft_strlen(src);
	new_src = (char *)malloc(src_length + 1 * sizeof(char));
	if (!(new_src))
		return (0);
	i = 0;
	while (src[i])
	{
		new_src[i] = src[i];
		++i;
	}
	new_src[i] = '\0';
	return (new_src);
}
