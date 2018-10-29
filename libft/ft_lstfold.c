/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:36:39 by iradchen          #+#    #+#             */
/*   Updated: 2017/11/19 10:45:57 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstfold(t_list *lst, int (*f)(int, int))
{
	int	res;

	if (!lst || !f)
	{
		ft_putendl("NULL pointer in parameters return 0");
		return (0);
	}
	res = *((int *)lst->content);
	lst = lst->next;
	while (lst)
	{
		res = f(res, *((int *)lst->content));
		lst = lst->next;
	}
	return (res);
}
