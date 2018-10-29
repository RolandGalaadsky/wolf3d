/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 17:29:56 by iradchen          #+#    #+#             */
/*   Updated: 2017/11/09 20:28:31 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *ptr_dst;
	unsigned char *ptr_src;
	unsigned char b;

	b = (unsigned char)c;
	ptr_dst = (unsigned char *)dst;
	ptr_src = (unsigned char *)src;
	while (n)
	{
		*ptr_dst = *ptr_src;
		if (*ptr_src == b)
		{
			ptr_dst++;
			return ((void *)ptr_dst);
		}
		ptr_dst++;
		ptr_src++;
		n--;
	}
	return (NULL);
}
