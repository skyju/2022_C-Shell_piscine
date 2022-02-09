/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 20:59:53 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/09 18:17:23 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_to_uppercase(char *str)
{
	int	x;

	x = 'a' - 'A';
	if (*str != '\0')
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= x;
	}
}

char	*ft_strcapitalize(char *str)
{	
	int	i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
			*(str + i) += 32;
		++i;
	}
	i = 0;
	ft_to_uppercase(str);
	while (*(str + i))
	{
		if (*(str + i) >= 32 && *(str + i) <= 47)
			ft_to_uppercase(str + i + 1);
		if (*(str + i) >= 91 && *(str + i) <= 96)
			ft_to_uppercase(str + i + 1);
		if (*(str + i) >= 123 && *(str + i) <= 126)
			ft_to_uppercase(str + i + 1);
		if (*(str + i) >= 58 && *(str + i) <= 64)
			ft_to_uppercase(str + i + 1);
		++i;
	}
	return (str);
}
