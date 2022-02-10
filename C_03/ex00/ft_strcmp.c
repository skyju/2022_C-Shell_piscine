/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:07:37 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/10 17:56:48 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int				i;
	unsigned char	temp_s1;
	unsigned char	temp_s2;

	i = 0;
	while (*(s1 + i) || *(s2 + i))
	{
		if (*(s1 + i) != *(s2 + i))
		{
			temp_s1 = *(s1 + i);
			temp_s2 = *(s2 + i);
			return (temp_s1 - temp_s2);
		}
		++i;
	}
	return (0);
}
