/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:11:06 by iradchen          #+#    #+#             */
/*   Updated: 2017/11/18 17:35:23 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		flag;

	flag = 0;
	while (*s)
	{
		flag = flag || (*s == c);
		s++;
	}
	while (flag || c == '\0')
	{
		if (*s == c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}
