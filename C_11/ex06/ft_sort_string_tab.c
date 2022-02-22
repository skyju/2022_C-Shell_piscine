/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:12:15 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/22 16:53:29 by mkwak            ###   ########.fr       */
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

void ft_sort_string_tab(char **tab)
{
	int i;
	int j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (ft_strcmp(tab[i], tab[j]) > 0)
				ft_swap(&tab[i], &tab[j]);
			++j;
		}
		++i;
	}
}

int main(void)
{
	printf("\n--ex06--\n");
	char *strs[8];
	strs[0] = "3s!!ZSDFAA~~mlkjs11";
	strs[1] = "ASss";
	strs[2] = "~9~~mlkjsyou";
	strs[3] = "!!09~~mlkjsyou";
	strs[4] = "mlAABkjs";
	strs[5] = "";
	strs[6] = "A z ~ ~";
	strs[7] = 0;
	printf("\nBefore sort\n");
	for (int i = 0; i < 7; i++)
		printf("%s\n", strs[i]);
	ft_sort_string_tab(strs);
	printf("\nAfter sort\n");
	for (int i = 0; i < 7; i++)
		printf("%s\n", strs[i]);
}