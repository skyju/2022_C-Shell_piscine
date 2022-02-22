/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_result.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhchoi <yunhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:27:03 by yunhchoi          #+#    #+#             */
/*   Updated: 2022/02/20 21:01:27 by yunhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	if (!src)
		return (NULL);
	i = ft_strlen(dest);
	j = 0;
	if (i != 0)
	{
		dest[i] = ' ';
		i++;
	}
	while (src[j] != 0)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = 0;
	return (dest);
}

char	*get_t_dict_value(int n)
{
	int	i;

	i = 0;
	while (g_number_dict[i] != NULL)
	{
		if (g_number_dict[i]->num == n)
			return (g_number_dict[i]->value);
		i++;
	}
	return (NULL);
}

char	*malloc_dict(char *str1, char *str2, char *str3)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = 0;
	if (str1)
		len = ft_strlen(str1);
	if (str2)
		len += ft_strlen(str2) + 1;
	if (str3)
		len += ft_strlen(str3) + 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
	{
		write(1, "memory allocation fail!", 23);
		return (NULL);
	}
	while (i < len + 1)
	{
		str[i++] = 0;
	}
	return (str);
}

void	char_dict_init(void)
{
	int	i;

	i = -1;
	while (++i <= 100)
	{
		if (i < 20 || i % 10 == 0)
		{
			if (!get_t_dict_value(i))
				continue ;
			g_result[i] = malloc_dict(get_t_dict_value(i), 0, 0);
			ft_strcat(g_result[i], get_t_dict_value(i));
		}
	}
	g_result[1000] = 0;
}

int	fill_result(void)
{
	g_result = (char **)malloc(1001 * sizeof(char *));
	if (!g_result)
	{
		write(2, "memory allocation error", 23);
		return (-1);
	}
	char_dict_init();
	fill_2num();
	fill_3num();
	free(g_result[100]);
	g_result[100] = malloc_dict("one hundred", 0, 0);
	ft_strcat(g_result[100], "one hundred");
	return (0);
}
