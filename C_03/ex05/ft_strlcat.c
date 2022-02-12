/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:57:37 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/10 17:57:08 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_str_length(char *str)
{
	unsigned int	count;

	count = 0;
	while (*(str + count))
		++count;
	return (count);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_length;
	unsigned int	src_length;
	unsigned int	index;

	dest_length = ft_str_length(dest);
	src_length = ft_str_length(src);
	index = 0;
	while (*(src + index) && dest_length + index + 1 < size)
	{
		*(dest + dest_length + index) = *(src + index);
		++index;
	}
	*(dest + dest_length + index) = '\0';
	if (size < dest_length)
		return (src_length + size);
	return (src_length + dest_length);
}
