/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reduce_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:48:30 by iradchen          #+#    #+#             */
/*   Updated: 2017/11/19 11:08:41 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_reduce_arr(int *arr, int (*f)(int, int), size_t len)
{
	size_t	i;
	int		res;

	if (!arr || !f)
	{
		ft_putendl("NULL pointer in parameters return 0");
		return (0);
	}
	res = arr[0];
	i = 1;
	while (i < len)
	{
		res = f(res, arr[i]);
		i++;
	}
	return (res);
}
