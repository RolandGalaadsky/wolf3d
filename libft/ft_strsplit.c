/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:08:13 by iradchen          #+#    #+#             */
/*   Updated: 2017/11/19 13:53:51 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	c_words(char const *s, char c)
{
	size_t	count;
	int		flag;

	count = 0;
	while (*s)
	{
		flag = 0;
		while (*s != c && *s)
		{
			flag = 1;
			s++;
		}
		if (flag)
			count++;
		if (*s)
			s++;
	}
	return (count);
}

static	char	*f_word(char **s, char c)
{
	size_t	len;
	char	*res;

	len = 0;
	while (**s == c && **s)
		(*s)++;
	while ((*s)[len] != c && (*s)[len])
		len++;
	res = ft_strsub(*s, 0, len);
	*s += len;
	return (res);
}

static	void	free_arr(char ***arr, size_t index)
{
	size_t i;

	i = 0;
	while (i <= index)
	{
		ft_memdel((void **)arr[i]);
		i++;
	}
	ft_memdel((void **)arr);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	r_len;
	size_t	i;
	char	*new_s;

	if (!s)
		return (NULL);
	r_len = c_words(s, c);
	res = (char **)malloc(sizeof(char *) * (r_len + 1));
	if (!res)
		return (NULL);
	res[r_len] = NULL;
	i = 0;
	new_s = (char *)s;
	while (i < r_len)
	{
		res[i] = f_word(&new_s, c);
		if (!res[i])
		{
			free_arr(&res, i);
			return (res);
		}
		i++;
	}
	return (res);
}
