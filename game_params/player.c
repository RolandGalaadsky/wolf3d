/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:35:11 by iradchen          #+#    #+#             */
/*   Updated: 2018/06/15 14:35:13 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"
#define MV_SPEED 5
#define RT_SPEED 2
#define BOX_CORD(x) (x * BLOCK_SIZE + BLOCK_SIZE / 2)

t_mv_params		*init_mv_params(int forward, int back, int speed)
{
	t_mv_params *params;

	params = (t_mv_params *)ft_memalloc(sizeof(t_mv_params));
	check_malloc(params);
	params->forward = forward;
	params->back = back;
	params->speed = speed;
	return (params);
}

t_rot_params	*init_rot_params(int left, int right, int speed)
{
	t_rot_params *params;

	params = (t_rot_params *)ft_memalloc(sizeof(t_rot_params));
	check_malloc(params);
	params->left = left;
	params->right = right;
	params->speed = speed;
	return (params);
}

void			init_player(t_scene *scene, int x, int y)
{
	t_player *player;

	player = (t_player *)ft_memalloc(sizeof(t_player));
	check_malloc(player);
	player->mv = init_mv_params(FALSE, FALSE, MV_SPEED);
	player->rot = init_rot_params(FALSE, FALSE, RT_SPEED);
	player->pos = get_vec_2(BOX_CORD(x), BOX_CORD(y));
	player->angle_step = (double)FOV / PROJ_WIDTH;
	scene->player = player;
}
