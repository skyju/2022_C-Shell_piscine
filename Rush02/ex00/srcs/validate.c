/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhchoi <yunhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:30:13 by yunhchoi          #+#    #+#             */
/*   Updated: 2022/02/20 21:06:36 by yunhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	validate_key(char *key)
{
	if (!key)
		return (-1);
	while (*key && *key == ' ')
		key++;
	while ('0' <= *key && *key <= '9')
		key++;
	while (*key == ' ')
		key++;
	if (*key)
		return (-1);
	return (1);
}

int	validate_dict(char **words)
{
	if (count_arr(words) != 2)
		return (-1);
	if (validate_key(words[0]) == -1)
		return (-1);
	return (1);
}

int	validate_digit(char *digit)
{
	if (*digit++ != '1')
		return (-1);
	while (*digit)
	{
		if (*digit++ != '0')
			return (-1);
	}
	return (1);
}

int	validate_input(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 1 && str[0] == '0')
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (1);
}

int	validate_node(int digit, int offset, char *set, char *str)
{
	int	i;
	int	j;

	j = 0;
	if (digit == 1 && str[0] == '0')
	{
		if (g_result[0] == NULL)
			return (-1);
		return (1);
	}
	while (digit--)
	{
		clear_set(set);
		i = offset;
		if (offset != 3)
			offset = 3;
		ft_memcpy(&set[3 - i], &str[j], i);
		if (!g_result[ft_atoi(set)] || (digit > 0 && !get_digit(digit)))
			return (-1);
		j += i;
	}
	return (1);
}
