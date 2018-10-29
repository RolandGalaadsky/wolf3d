/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:53:16 by iradchen          #+#    #+#             */
/*   Updated: 2017/11/10 12:47:09 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	size_t	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	res = ft_strnew(ft_strlen(s));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = f(s[i]);
		i++;
	}
	return (res);
}
