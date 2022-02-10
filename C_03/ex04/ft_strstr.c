/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:44:08 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/10 14:49:29 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		index;

	index = 0;
	if (*to_find == '\0')
		return (str);
	while (*str)
	{	
		index = 0;
		while (*(str + index) == *(to_find + index))
		{	
			++index;
			if (*(to_find + index) == '\0')
				return (str);
		}
		++str;
	}
	return (0);
}
