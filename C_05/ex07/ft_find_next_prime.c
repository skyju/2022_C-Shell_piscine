/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:22:48 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/12 17:35:01 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft__is_prime(int nb)
{
	int	n;

	n = 2;
	if (nb < 2)
		return (0);
	while (n < nb)
	{
		if (nb % n == 0)
			return (0);
		++n;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!ft__is_prime(nb) && nb < 2147483647)
		++nb;
	return (nb);
}
