/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 21:22:36 by iradchen          #+#    #+#             */
/*   Updated: 2017/11/18 16:39:16 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define COND1(c) (c == ' ' || c == '\n' || c == '\t')
#define COND2(c) (c == '\v' || c == '\f' || c == '\r')
#define CHECKBLANKS(c) (COND1(c) || COND2(c))

int				ft_atoi(const char *str)
{
	int	sign;
	int	res;

	res = 0;
	sign = 1;
	while (CHECKBLANKS(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		res = 10 * res + sign * (*str - '0');
		str++;
	}
	return (res);
}
