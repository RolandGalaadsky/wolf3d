/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_cast_fun.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:12:47 by iradchen          #+#    #+#             */
/*   Updated: 2018/06/15 16:12:52 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

void	set_common_params(t_cast *cast, int type)
{
	cast->type = type;
	cast->pos = get_vec_2(0, 0);
	cast->dir = get_vec_2(0, 0);
}

void	del_common_params(t_cast *cast)
{
	ft_memdel((void **)&cast->pos);
	ft_memdel((void **)&cast->dir);
}
