/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:12:15 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/22 16:55:20 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_swap(char **s1, char **s2)
{
	char *temp;

	temp = *s1;
	*s1 = *s2;
	*s2 = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[j])
		{
			if (tab[j + 1] && (*cmp)(tab[j], tab[j + 1]) > 0)
				ft_swap(&tab[j], &tab[j + 1]);
			++j;
		}
		++i;
	}
}



int decending_cmp(char *str1, char *str2)
{
	while (*str1 && *str2)
	{
		if (*str1 != *str2)
			break;
		str1++;
		str2++;
	}
	return (*str2 - *str1);
}


int main(void)
{
	printf("\n--ex07--\n");
	char *strs[8];
	char *strss[3];
	strss[0] = "3";
	strss[1] = "1";
	strss[2] = "2";
	strs[0] = "3bhhiu92809~~mlkjs";
	strs[1] = "ASss";
	strs[2] = "~9~~mlkjsyou";
	strs[3] = "!!09~~mlkjsyou";
	strs[4] = "mlAABkjs";
	strs[5] = "";
	strs[6] = "  zz~~";
	strs[7] = 0;
	printf("\n[ Before decending sort ]\n");
	for (int i = 0; i < 7; i++)
		printf("%s\n", strs[i]);
	ft_advanced_sort_string_tab(strs, &decending_cmp);
	printf("\n[ After decending sort ]\n");
	for (int i = 0; i < 7; i++)
		printf("%s\n", strs[i]);
	printf("\n[ After decending sort ]\n");
	ft_advanced_sort_string_tab(strss, &decending_cmp);
	for (int i = 0; i < 3 ; i++)
		printf("%s\n", strss[i]);
}
