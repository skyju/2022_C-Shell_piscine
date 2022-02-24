/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcspn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 18:21:32 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/24 18:51:29 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strcspn(const char *s, const char *reject)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	res;

	i = 0;
	res = 0;
	while (*s)
	{
		j = 0;
		if (s[j] == reject[j])
			res = i;
		while (s[j] == reject[j])
		{
			++j;
			if (reject[j] == '\0')
				return res;
		}
		++s;
		++i;
	}
	return (0);
}

int	main(void)
{
	char *str = "minju minju minminju asdf qwer";
	char *to_find = "asdf";
	unsigned int i;

	i = ft_strcspn(str, to_find);
	printf("Position is : index number %d!\n", i);
}
