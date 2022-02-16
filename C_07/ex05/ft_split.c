/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 10:17:20 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/16 13:22:55 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/* 토큰문자열 갯수를 구하는 함수*/
static size_t k_cntword(const char *s, char c)
{
	size_t	cnt;
	size_t	flag;

	cnt = 0;
	flag = 0;
	while (*s != NULL)
	{
		if (*s != c && flag == 0)
		{
			flag = 1;
			cnt++;
		}
		else if (*s == c)
			flag = 0;
		s++;
	}
	return (cnt);
}

/* 각토큰문자열의 길이를 구하는 함수*/
static size_t k_wordlen(char const *s, char c)
{
	size_t len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

/* 토큰문자열 한개를 새로운 메모리에 복사하는 함수 */
static char *k_strndup(const char *s, size_t num)
{
	char	*word;

	if (!(word = (char *)malloc(sizeof(char) * (num + 1))))
		return (0);
	while (num-- > 0)
		*word++ = *s++;

	*word = '\0';
	return (word);
}

/* 이차원배열의 메모리를 해제하는 함수 */
static void k_free_str(char **s, int i)
{
	while (i-- > 0)
	{
		free(s[i]);
		s[i] = NULL;
	}
	free(s);
	s = NULL;
}

/* split 본 함수 */
char **split(char const *str, char *c)
{
	size_t	nb;
	size_t	wordlen;
	size_t	cnt;
	char    **result;

	cnt = k_cntword(str, c);
	if (!(result = (char **)malloc(sizeof(char *) * (cnt + 1))))
		return (0);
	nb = 0;
	while (nb < cnt)
	{
		while (*str && *str == c)
			str++;
		wordlen = k_wordlen(str, c);
		if (!(result[nb] = k_strndup(str, wordlen)))
		{
			k_free_str(result, nb);
			return (0);
		}
		str += wordlen;
		nb++;
	}
	result[cnt] = 0;
	return (result);
}

/*
int	ft_token_num(char *str, char c)
{
	int	cnt;
	int	flag;

	cnt = 0;
	flag = 0;
	while (*str)
	{
		if(*str != c && flag == 0)
		{
			flag = 1;
			++cnt;
		}
		else if (*str == c)
			flag = 0;
		++str;
	}
	return (cnt);
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
{
	int	str_length;
	int	charset_length;

	str_length = ft___strlen(str);
	charset_length = ft___strlen(charset);

}
*/
