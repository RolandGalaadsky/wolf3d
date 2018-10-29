/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 15:50:39 by iradchen          #+#    #+#             */
/*   Updated: 2017/11/18 17:06:56 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *p_dst;
	unsigned char *p_src;

	p_src = (unsigned char *)src;
	p_dst = (unsigned char *)dst;
	if (dst < src)
	{
		while (len)
		{
			*p_dst = *p_src;
			p_dst++;
			p_src++;
			len--;
		}
	}
	else if (dst > src)
	{
		while (len)
		{
			*(p_dst + len - 1) = *(p_src + len - 1);
			len--;
		}
	}
	return (dst);
}
