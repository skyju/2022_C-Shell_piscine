/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:28:27 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/15 19:28:30 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft__is_prime(int nb)
{
	int	n;

	n = 2;
	if (nb < 2)
		return (0);
	while (n <= nb / n)
	{
		if (nb % n == 0)
			return (0);
		++n;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (!ft__is_prime(nb) && nb <= 2147483647)
		++nb;
	return (nb);
}
