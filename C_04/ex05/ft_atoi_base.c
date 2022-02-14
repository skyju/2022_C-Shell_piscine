/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:22:48 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/14 17:25:52 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_my_strstr(char *str, char to_find)
{
	while (*str)
	{	
		if (*(str) == to_find)
			return (1);
		++str;
	}
	return (0);
}

int	ft_base_checking(char *base)
{
	int		check;
	int		i;

	i = 0;
	check = 0;
	while (*(base + i))
	{
		if (*(base + i) == '-' || *(base + i) == '+' || *(base + i) == ' '
			|| *(base + i) == '\f' || *(base + i) == '\n' || *(base + i) == '\r'
			|| *(base + i) == '\t' || *(base + i) == '\v')
			check = 1;
		if (ft_my_strstr((base + i + 1), *(base + i)))
			check = 1;
		++i;
	}
	return (check);
}

int	ft_base_cal(char c, char *base)
{
	int		i;

	i = 0;
	while (*(base + i))
	{
		if (c == *(base + i))
			return (i);
		++i;
	}
	return (-1);
}

int	ft_calculator(char *str, int index, int obase, char *base)
{	
	int	minus;
	int	result;
	int	i;

	i = index;
	minus = 0;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			++minus;
		++i;
	}
	result = 0;
	while (ft_base_cal(str[i], base) != -1)
	{
		result *= obase;
		result += ft_base_cal(str[i], base);
		++i;
	}
	if (minus % 2 == 1)
		result *= -1;
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	obase;
	int	check;
	int	i;
	int	result;

	obase = 0;
	while (*(base + obase))
		++obase;
	check = ft_base_checking(base);
	if (obase == 0 || obase == 1 || check == 1)
		return (0);
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		++i;
	result = ft_calculator(str, i, obase, base);
	return (result);
}

int main(void)
{
	char *str1 = "   ---+--+AABCDESSEZ";
	char *str2 = "  \n \ta-a";
	char *str3 = " \v  ++2147483648";
	char *str4 = " \f  -----+-+!!@@#..<";
	char *str5 = "\r  \n -+-++-+2147483648";
	printf("10\n");
	printf("%d\n", ft_atoi_base("---+-1010", "01")); //2base
	printf("\n");
	printf("-67174\n");
	printf("%d\n", ft_atoi_base(str1, "ABCDES")); // 6base
	printf("\n");
	printf("-1\n");
	printf("%d\n", ft_atoi_base(str1, "ABZ")); 	
	printf("\n");
	printf("0\n");
	printf("%d\n", ft_atoi_base(str3, "AWS")); // +- include
	printf("\n");
	printf("0\n");
	printf("%d\n", ft_atoi_base(str1, "")); // 0base
	printf("\n");
	printf("-2147483648\n");
	printf("%d\n", ft_atoi_base(str5, "0123456789")); // 10base
	printf("\n");
	printf("2\n");
	printf("%d\n", ft_atoi_base(str2, "cba")); // 3base
	printf("\n");
	printf("1126397\n");
	printf("%d\n", ft_atoi_base(str4, "!@#$%^&*()~?><'.")); // 16base
	printf("\n");
	return 0;
}