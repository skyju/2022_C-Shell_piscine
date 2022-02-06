/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:54:21 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/03 15:16:45 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{	
	char	char_p;
	char	char_n;

	char_p = 'P';
	char_n = 'N';
	if (n >= 0)
	{	
		write(1, &char_p, 1);
	}
	else
	{
		write(1, &char_n, 1);
	}
}
