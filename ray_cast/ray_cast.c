/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:41:36 by iradchen          #+#    #+#             */
/*   Updated: 2018/06/15 17:41:37 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

void	get_type_and_dist_draw_params(t_cast *cast, t_scene *scene)
{
	int		**map;
	double	*pos;
	double	c_x;
	double	c_y;

	map = scene->map;
	pos = scene->player->pos;
	cast->dist_to_inter = DBL_MAX;
	cast->wall_type = -1;
	while (VALID_CORD(cast->pos, scene))
	{
		if (map[GET_ON_MAP(cast->pos[Y])][GET_ON_MAP(cast->pos[X])])
		{
			c_x = cast->pos[X];
			c_y = cast->pos[Y];
			cast->dist_to_inter = sqrt(SQ(c_y - pos[Y]) \
				+ SQ(c_x - pos[X]));
			cast->wall_type = map[GET_ON_MAP(c_y)][GET_ON_MAP(c_x)];
			cast->wall_type--;
			return ;
		}
		cast->pos[X] += cast->dir[X];
		cast->pos[Y] += cast->dir[Y];
	}
}

void	del_casts_params(t_cast *h_cast, t_cast *v_cast)
{
	del_common_params(h_cast);
	del_common_params(v_cast);
}

void	ray_cast(t_sdl_staff *sdl_staff, t_scene *scene)
{
	t_cast	h_cast;
	t_cast	v_cast;
	double	tang;
	double	angle;
	int		x;

	x = 0;
	angle = scene->player->pov - FOV / 2;
	if (angle < 0)
		angle += PERIOD;
	set_common_params(&v_cast, V);
	set_common_params(&h_cast, H);
	while (x < PROJ_WIDTH)
	{
		tang = tan(angle * RADIAN);
		h_cast.x_on_proj_plane = x;
		v_cast.x_on_proj_plane = x;
		set_cast(&h_cast, angle, scene->player, tang);
		set_cast(&v_cast, angle, scene->player, tang);
		draw_col(&h_cast, &v_cast, scene, sdl_staff);
		x++;
		angle += scene->player->angle_step;
		angle = angle > PERIOD ? angle - PERIOD : angle;
	}
	del_casts_params(&h_cast, &v_cast);
}
