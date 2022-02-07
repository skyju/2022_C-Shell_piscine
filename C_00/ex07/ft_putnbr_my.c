/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkwak <mkwak@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:43:57 by mkwak             #+#    #+#             */
/*   Updated: 2022/02/05 20:18:49 by mkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchars(char c)
{
	write(1, &c, 1);
}

void my_cal(int cnt, int nb)
{   
    char    c;
    
    while(cnt > 1)
    {   
        nb /= 10;
        --cnt;
    }
    c = (nb % 10)+48;
    ft_putchars(c);
}

int count(int nb)
{
    int count;
    int n;

    n = nb;
    count = 0;
    while(n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

void    ft_putnbr(int nb)
{   
    int cnt;

    if (nb == -2147483648)
    {
        write(1, "-2147483648", 11);
        return ;
    }
    else if (nb < 0)
    {
        ft_putchars('-');
        nb *= -1;
    }
    cnt = count(nb);
    while (cnt > 0)
    {
        my_cal(cnt, nb);
        --cnt;
    }
}
