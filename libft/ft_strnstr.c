/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 20:52:38 by iradchen          #+#    #+#             */
/*   Updated: 2017/11/18 17:32:04 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	char	new_big[len + 1];
	char	*sub;

	if (little && !ft_strcmp(little, ""))
		return ((char *)big);
	ft_strncpy(new_big, big, len);
	new_big[len] = '\0';
	sub = ft_strstr(new_big, little);
	if (sub && ft_strcmp(sub, ""))
		return (ft_strstr(big, sub));
	return (NULL);
}
