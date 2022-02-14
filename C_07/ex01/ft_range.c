/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:17:20 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/14 10:40:25 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_size(int min, int max)
{
	int	size;

	size = max - min;
	if(size < 0)
		size *= -1;
	return (size);
}

int	*ft_range(int min, int max)
{
	int	*arr;

	if (min >= max)
		return (0);
	arr = (int *)malloc(ft_size(min, max) * sizeof(int));
	
}