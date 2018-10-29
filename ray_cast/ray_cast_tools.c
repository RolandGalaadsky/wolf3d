/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:59:08 by iradchen          #+#    #+#             */
/*   Updated: 2018/06/15 17:59:09 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

void	change_tang(t_cast *cast, double *mult)
{
	int cond;

	if (cast->type == H)
		cond = cast->angle > H_DOWN && cast->angle < H_TOP;
	else
		cond = cast->angle > V_DOWN && cast->angle < V_TOP;
	if (cond)
		*mult *= (*mult > 0) ? -1 : 1;
	else
		*mult *= (*mult < 0) ? -1 : 1;
}

void	set_one_cord(int cord, t_player *player, t_cast *cast)
{
	int cond;

	if (cast->type == H)
		cond = cast->angle >= V_DOWN && cast->angle < V_TOP;
	else
		cond = cast->angle >= H_DOWN && cast->angle < H_TOP;
	cast->pos[cord] = GET_ON_MAP(player->pos[cord]) * BLOCK_SIZE;
	if (cond)
	{
		cast->pos[cord] -= 0.0001;
		cast->dir[cord] = -BLOCK_SIZE;
	}
	else
	{
		cast->pos[cord] += BLOCK_SIZE;
		cast->dir[cord] = BLOCK_SIZE;
	}
}

void	set_second_cord(int *cords, t_player *player, t_cast *cast, double mult)
{
	int cord1;
	int cord2;

	cord1 = cords[0];
	cord2 = cords[1];
	cast->pos[cord2] = player->pos[cord2] + \
	(cast->pos[cord1] - player->pos[cord1]) * mult;
	change_tang(cast, &mult);
	cast->dir[cord2] = BLOCK_SIZE * mult;
}

void	set_cords(t_player *player, t_cast *cast, double tang)
{
	int cords[2];

	cords[0] = X;
	cords[1] = Y;
	if (cast->type == V)
	{
		set_one_cord(cords[0], player, cast);
		set_second_cord(cords, player, cast, tang);
	}
	else
	{
		ft_swap_int(&cords[0], &cords[1]);
		set_one_cord(cords[0], player, cast);
		set_second_cord(cords, player, cast, 1 / tang);
	}
}

void	set_cast(t_cast *cast, double angle, t_player *player, double tang)
{
	cast->angle = angle;
	set_cords(player, cast, tang);
}
