/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 21:26:55 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/09 18:29:38 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_cal_length(char *str)
{
	unsigned int	i;

	i = 0;
	while (*(str + i))
		++i;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_length;

	i = 0;
	src_length = ft_cal_length(src);
	while (*(src + i) && i < size - 1 && size != 0)
	{
		*(dest + i) = *(src + i);
		++i;
	}
	if (size > 0)
		*(dest + i) = '\0';
	return (src_length);
}
