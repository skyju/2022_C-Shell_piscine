/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:26:55 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/08 21:55:36 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		++i;
	}
	if ((int)size > 0)
		*(dest + i) = '\0';
	return (i);
}
