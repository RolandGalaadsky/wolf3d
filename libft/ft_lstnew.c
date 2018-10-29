/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:09:50 by iradchen          #+#    #+#             */
/*   Updated: 2017/11/19 11:29:55 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->next = NULL;
	if (!content)
	{
		node->content = NULL;
		node->content_size = 0;
		return (node);
	}
	node->content = ft_memalloc(content_size);
	if (!(node->content))
	{
		free(node);
		return (NULL);
	}
	ft_memcpy(node->content, content, content_size);
	node->content_size = content_size;
	return (node);
}
