/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:35:18 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/22 18:49:15 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putstr(char *str);
void	ft_putnbr(int nbr);
int		ft_atoi(char *str);
int		do_op_plus(int v1, int v2);
int		do_op_minus(int v1, int v2);
int		do_op_div(int v1, int v2);
int		do_op_mod(int v1, int v2);
int		do_op_multiply(int v1, int v2);

char	is_op(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i > 0)
		{
			ft_putstr("0");
			return (-1);
		}
		++i;
	}
	i = 0;
	if (str[i] == '+' || str[i] == '-' || str[i] == '/'
		|| str[i] == '*' || str[i] == '%')
		return (str[i]);
	ft_putstr("0");
	return (-1);
}

void	ft_error_by_zero(char op)
{
	if (op == '/')
		ft_putstr("Stop : division by zero");
	else
		ft_putstr("Stop : modulo by zero");
}

void	ft_calculator(int v1, int v2, char *o, int(*f[])(int, int))
{
	char	op;

	op = is_op(o);
	if (op == -1)
		return ;
	if (v2 == 0 && (op == '/' || op == '%'))
	{
		ft_error_by_zero(op);
		return ;
	}
	else if (op == '-')
		ft_putnbr((*f[0])(v1, v2));
	else if (op == '+')
		ft_putnbr((*f[1])(v1, v2));
	else if (op == '*')
		ft_putnbr((*f[2])(v1, v2));
	else if (op == '/')
		ft_putnbr((*f[3])(v1, v2));
	else
		ft_putnbr((*f[4])(v1, v2));
}

int	main(int argc, char **argv)
{
	int		value1;
	int		value2;
	int		(*f[5])(int, int);
	char	*op;

	if (argc != 4)
		return (0);
	value1 = ft_atoi(argv[1]);
	value2 = ft_atoi(argv[3]);
	op = argv[2];
	f[0] = &do_op_minus;
	f[1] = &do_op_plus;
	f[2] = &do_op_multiply;
	f[3] = &do_op_div;
	f[4] = &do_op_mod;
	ft_calculator(value1, value2, op, f);
	ft_putstr("\n");
	return (0);
}
