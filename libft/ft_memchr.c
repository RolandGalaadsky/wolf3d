/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 20:57:47 by iradchen          #+#    #+#             */
/*   Updated: 2017/11/04 21:06:33 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char b;
	unsigned char *p_s;

	p_s = (unsigned char*)s;
	b = (unsigned char)c;
	while (n)
	{
		if (*p_s == b)
			return ((void *)p_s);
		p_s++;
		n--;
	}
	return (NULL);
}
