/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 19:46:02 by iradchen          #+#    #+#             */
/*   Updated: 2017/11/18 17:32:47 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t l_lit;

	l_lit = ft_strlen(little);
	if (little && !ft_strcmp(little, ""))
		return ((char *)big);
	while (*big)
	{
		if (!ft_strncmp(big, little, l_lit))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
