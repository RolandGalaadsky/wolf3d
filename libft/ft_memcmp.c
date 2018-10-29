/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 21:07:54 by iradchen          #+#    #+#             */
/*   Updated: 2017/11/09 19:22:12 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *p_s1;
	unsigned char *p_s2;

	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n - 1 && *p_s1 == *p_s2)
	{
		n--;
		p_s1++;
		p_s2++;
	}
	return (*p_s1 - *p_s2);
}
