/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:35:31 by yunhchoi          #+#    #+#             */
/*   Updated: 2022/02/20 16:42:56 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# define BUF_SIZE 4096

typedef struct s_dict
{
	char	*key;
	char	*value;
	int		num;
	int		digit;
}			t_dict;

t_dict		**g_number_dict;
t_dict		**g_digit_dict;
char		**g_result;

t_dict		**get_dict(char *file);
int			init_dict(char *dict);
char		*get_digit(int n);
char		*malloc_dict(char *str1, char *str2, char *str3);
char		**get_lines(char *file);
int			fill_result(void);
int			fill_2num(void);
int			fill_3num(void);
void		clear_set(char *set);
int			validate_input(char *str);
int			validate_key(char *key);
int			validate_dict(char **words);
int			validate_digit(char *digit);
int			validate_node(int digit, int offset, char *set, char *str);
t_dict		*creat_node(char *key, char *val);
int			add_node(char **words, t_dict **list, int idx);
char		*rstrip(char *word);
char		*lstrip(char *word);
int			count_arr(char **words);
void		free_list(t_dict **list);
void		free_all(void);
void		free_words(char **strs);
void		ft_print(char *str);
char		**ft_split(char *str, char sep);
char		*ft_strcat(char *dest, char *src);
int			ft_atoi(char *str);
int			ft_strlen(char *str);
void		ft_memcpy(void *dst, void *src, unsigned int len);
#endif
