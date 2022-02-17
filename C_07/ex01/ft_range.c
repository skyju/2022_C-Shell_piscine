/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:17:20 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/17 13:18:53 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	index;

	if (min >= max)
	{
		return (0);
	}
	arr = (int *)malloc((max - min) * sizeof(int));
	if (arr == 0)
		return (0);
	index = 0;
	while (index < (max - min))
	{	
		arr[index] = min + index;
		++index;
	}
	return (arr);
}
