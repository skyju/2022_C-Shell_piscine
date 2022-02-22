/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunhchoi <yunhchoi@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 16:27:31 by yunhchoi          #+#    #+#             */
/*   Updated: 2022/02/20 16:29:26 by yunhchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	return (c == ' ');
}

int	is_digit(char c)
{
	return ('0' <= c && c <= '9');
}

int	char_to_int(char *str, int digit)
{
	if (!is_digit(*str))
		return (0);
	return ((*str - '0') * digit + char_to_int(str - 1, digit * 10));
}

int	ft_atoi(char *str)
{
	int		sign;
	char	*origin;

	sign = 1;
	origin = str;
	while (is_space(*str))
		str++;
	if (!is_digit(*str))
		return (0);
	while (is_digit(*str))
		str++;
	return (char_to_int(str - 1, 1) * sign);
}
