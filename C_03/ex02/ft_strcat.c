/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 20:38:27 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/10 12:21:22 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_cal_str_length(char *str)
{
	int	count;

	count = 0;
	while (*(str + count))
		++count;
	return (count);
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_length;
	int	src_i;

	dest_length = ft_cal_str_length(dest);
	src_i = 0;
	while (*(src + src_i))
	{
		*(dest + dest_length) = *(src + src_i);
		++dest_length;
		++src_i;
	}
	*(dest + dest_length) = '\0';
	return (dest);
}
