/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:14:47 by iradchen          #+#    #+#             */
/*   Updated: 2018/06/15 15:14:48 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

int		can_go(int **map, t_scene *scene, double *new, double *dir)
{
	double	buff[2];
	int		i;

	i = 0;
	if (!VALID_CORD(new, scene))
		return (FALSE);
	if (map[GET_ON_MAP(new[Y])][GET_ON_MAP(new[X])])
		return (FALSE);
	while (i < 3)
	{
		ft_memcpy(buff, new, 2 * sizeof(double));
		buff[X] += ((i == 0) ? -dir[X] : dir[X]);
		buff[Y] += ((i == 1) ? -dir[Y] : dir[Y]);
		if (!VALID_CORD(buff, scene))
			return (FALSE);
		if (map[GET_ON_MAP(buff[Y])][GET_ON_MAP(buff[X])])
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	change_position(t_player *player, int **map, t_scene *scene)
{
	double	new[2];
	double	dir[2];

	if (player->mv->forward || player->mv->back)
	{
		new[X] = player->pos[X];
		new[Y] = player->pos[Y];
		dir[X] = player->mv->speed * cos(player->pov * RADIAN);
		dir[Y] = player->mv->speed * sin(player->pov * RADIAN);
		if (player->mv->back)
		{
			dir[X] *= -1;
			dir[Y] *= -1;
		}
		new[X] += dir[X];
		new[Y] += dir[Y];
		if (can_go(map, scene, new, dir))
		{
			player->pos[X] = new[X];
			player->pos[Y] = new[Y];
		}
	}
}

void	change_pov(t_player *player)
{
	if (player->rot->left)
		player->pov -= player->rot->speed;
	if (player->rot->right)
		player->pov += player->rot->speed;
	if (player->pov >= PERIOD)
		player->pov -= PERIOD;
	if (player->pov < 0)
		player->pov += PERIOD;
}

void	update_player(t_scene *scene)
{
	change_pov(scene->player);
	change_position(scene->player, scene->map, scene);
}
