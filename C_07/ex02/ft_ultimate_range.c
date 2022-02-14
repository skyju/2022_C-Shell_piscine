/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:17:20 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/14 17:55:26 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	index;
	int	*result;

	if(min >= max)
	{
		*range = 0;
		return (0);
	}
	*range = result = (int *)malloc((max - min) * sizeof(int));
	index = 0;
	while (index < (max - min))
	{
		*(result + index) = min + index;
		++index;
	}
	if (!*result)
		return (-1);
	return (max - min);
}
