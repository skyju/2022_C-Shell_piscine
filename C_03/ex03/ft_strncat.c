/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:52:36 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/10 12:21:32 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_cal_length(char *str)
{
	unsigned int	count;

	count = 0;
	while (*(str + count))
		++count;
	return (count);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	dest_length;
	unsigned int	src_i;

	dest_length = ft_cal_length(dest);
	src_i = 0;
	while (*(src + src_i) && src_i < nb)
	{
		*(dest + dest_length) = *(src + src_i);
		++dest_length;
		++src_i;
	}
	*(dest + dest_length) = '\0';
	return (dest);
}
