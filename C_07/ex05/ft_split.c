/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:17:20 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/15 15:50:04 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*strstr(char *haystack, char *niddle)
{
	int	i;

	i = 0;
	while (*haystack)
	{
		while (haystack[i] == niddle[i])
		{
			++i;
			if (niddle[i] == '\0')
				return (haystack);
		}
		++haystack;
	}
}

int	ft___strlen(char *src)
{
	int	count;

	count = 0;
	while (src[count])
		++count;
	return (count);
}

char	**ft_split(char *str, char *charset)
{1
	int	str_length;
	int	charset_length;

	str_length = ft___strlen(str);
	charset_length = ft___strlen(charset);


}
