/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:55:30 by iradchen          #+#    #+#             */
/*   Updated: 2017/11/19 10:44:41 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_int(int *ptr1, int *ptr2)
{
	int temp;

	if (!ptr1 || !ptr2)
	{
		ft_putendl("NULL pointer in parameters");
		return ;
	}
	temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = temp;
}
