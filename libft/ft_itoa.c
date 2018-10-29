/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:50:25 by iradchen          #+#    #+#             */
/*   Updated: 2017/11/10 19:29:49 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define ABS(x) x > 0 ? x : -x

static int		nbr_l(int n)
{
	int count;

	count = (n == 0);
	while (n != 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

char			*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		d;
	int		end;
	int		sign;

	sign = n < 0;
	len = nbr_l(n) + sign;
	end = 1 + sign;
	res = ft_strnew(len);
	if (!res)
		return (NULL);
	if (n < 0)
		res[0] = '-';
	while (len >= end)
	{
		d = n % 10;
		d = ABS(d);
		res[len - 1] = '0' + d;
		n /= 10;
		len--;
	}
	return (res);
}
