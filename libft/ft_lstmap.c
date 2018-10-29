/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:43:20 by iradchen          #+#    #+#             */
/*   Updated: 2017/11/19 14:18:20 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		easy_free(t_list **first)
{
	if (!first)
		return ;
	if (*first)
		easy_free(&((*first)->next));
	free(*first);
	return ;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *temp;

	if (!lst || !f)
		return (NULL);
	new = f(lst);
	if (!new)
		return (NULL);
	temp = new;
	while (lst->next)
	{
		lst = lst->next;
		temp->next = f(lst);
		if (!(temp->next))
		{
			easy_free(&new);
			return (NULL);
		}
		temp = temp->next;
	}
	return (new);
}
