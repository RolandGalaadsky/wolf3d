/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_col_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 17:15:58 by iradchen          #+#    #+#             */
/*   Updated: 2018/06/15 17:16:00 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"
#define DIFF_BLOCK 11
#define GET_HEIGHT(dist) (ceil(DIST_TO_PROJ_PLANE * BLOCK_SIZE / dist))
#define GET_FISH_ANGLE(x, angle_step) (x * angle_step - 30)
#define CLIP_END(end_y) (end_y > PROJ_HEIGHT) ? PROJ_HEIGHT : end_y

void	find_draw_params(t_draw_params *draw_params, \
	t_scene *scene, t_cast *cast)
{
	int		x;
	double	angle_step;

	angle_step = scene->player->angle_step;
	x = cast->x_on_proj_plane;
	draw_params->cast = cast;
	if (draw_params->cast->type == V)
		draw_params->tex_pos_x = ((int)draw_params->cast->pos[Y]) % BLOCK_SIZE;
	else
		draw_params->tex_pos_x = ((int)draw_params->cast->pos[X]) % BLOCK_SIZE;
	cast->dist_to_inter *= cos(GET_FISH_ANGLE(x, angle_step) * RADIAN);
	draw_params->height = GET_HEIGHT(cast->dist_to_inter);
	draw_params->begin_y = (PROJ_HEIGHT - draw_params->height) / 2;
	draw_params->end_y = draw_params->begin_y + draw_params->height;
	draw_params->end_y = CLIP_END(draw_params->end_y);
}

Uint32	get_side_color(t_draw_params *draw_params, t_resources *resources, \
	int tex_pos_y)
{
	int cast_type;
	int cord;
	int w1;
	int w2;

	cast_type = draw_params->cast->type;
	if (cast_type == H)
	{
		cord = Y;
		w1 = 5;
		w2 = 3;
	}
	else
	{
		cord = X;
		w1 = 8;
		w2 = 0;
	}
	if (draw_params->cast->dir[cord] < 0)
		return (get_pixel(resources->textures[w1], draw_params->tex_pos_x, \
			tex_pos_y));
	else
		return (get_pixel(resources->textures[w2], draw_params->tex_pos_x, \
			tex_pos_y));
}

Uint32	get_color(t_draw_params *draw_params, int tex_pos_y, \
	t_resources *resources)
{
	int wall_type;

	wall_type = draw_params->cast->wall_type;
	if (wall_type == 10)
		return (get_side_color(draw_params, resources, tex_pos_y));
	if (draw_params->cast->type == H)
		return (darker(get_pixel(resources->textures[wall_type], \
			draw_params->tex_pos_x, tex_pos_y), 0.5));
	else
		return (get_pixel(resources->textures[wall_type], \
			draw_params->tex_pos_x, tex_pos_y));
}

t_cast	*nearest_cast(t_cast *h_cast, t_cast *v_cast)
{
	if (h_cast->dist_to_inter < v_cast->dist_to_inter)
		return (h_cast);
	else
		return (v_cast);
}
