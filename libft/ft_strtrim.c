/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:01:40 by iradchen          #+#    #+#             */
/*   Updated: 2017/11/18 17:33:37 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define ISWHITESPACE(x) x == ' ' || x == '\n' || x == '\t'

static void		from_begin(char const **s, size_t *len)
{
	while (ISWHITESPACE(**s))
	{
		(*s)++;
		(*len)--;
	}
}

static void		from_end(char const *s, size_t *len)
{
	if (*len < 1)
	{
		*len = 0;
		return ;
	}
	while (ISWHITESPACE(s[*len - 1]))
		(*len)--;
}

char			*ft_strtrim(char const *s)
{
	size_t	len;
	char	*new_s;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	from_begin(&s, &len);
	from_end(s, &len);
	new_s = ft_strnew(len);
	if (!new_s)
		return (NULL);
	while (i < len)
	{
		new_s[i] = *s;
		s++;
		i++;
	}
	return (new_s);
}
