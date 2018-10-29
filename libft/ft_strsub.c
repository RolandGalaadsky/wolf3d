/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:09:24 by iradchen          #+#    #+#             */
/*   Updated: 2017/11/19 15:28:55 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	end;

	end = len + start;
	i = start;
	if ((!s || ((end - 1 > ft_strlen(s)) && end != start)))
		return (NULL);
	sub = ft_strnew(len);
	if (!sub)
		return (NULL);
	while ((i < end) && s[i])
	{
		sub[i - start] = s[i];
		i++;
	}
	return (sub);
}
