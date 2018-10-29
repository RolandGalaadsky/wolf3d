/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_col.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:13:57 by iradchen          #+#    #+#             */
/*   Updated: 2018/06/15 16:13:58 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"
#define FLOOR_COLOR 0x111122
#define SKY_COLOR 0xcccccc
#define GET_TEX_Y(y, y0, h) ((y - y0) * BLOCK_SIZE) / (double)h

void	draw_floor(t_draw_params *draw_params, SDL_Surface *surface)
{
	int	y;

	y = PROJ_HEIGHT - 1;
	while (y > draw_params->end_y)
	{
		set_pixel(surface, draw_params->cast->x_on_proj_plane, y, FLOOR_COLOR);
		y--;
	}
}

void	draw_sky(t_draw_params *draw_params, SDL_Surface *surface)
{
	int	y;

	y = 0;
	while (y <= PROJ_HEIGHT / 2)
	{
		set_pixel(surface, draw_params->cast->x_on_proj_plane, y, SKY_COLOR);
		y++;
	}
}

void	draw_wall(t_draw_params *draw_params, t_sdl_staff *sdl_staff)
{
	int		y;
	t_cast	*cast;
	int		tex_pos_y;
	Uint32	color;

	cast = draw_params->cast;
	y = (draw_params->begin_y < 0) ? 0 : draw_params->begin_y;
	while (y < draw_params->end_y)
	{
		tex_pos_y = GET_TEX_Y(y, draw_params->begin_y, draw_params->height);
		color = get_color(draw_params, tex_pos_y, sdl_staff->resources);
		set_pixel(sdl_staff->surface, cast->x_on_proj_plane, y, color);
		y++;
	}
}

void	draw_col(t_cast *h_cast, t_cast *v_cast, \
	t_scene *scene, t_sdl_staff *sdl_staff)
{
	t_draw_params draw_params;

	get_type_and_dist_draw_params(h_cast, scene);
	get_type_and_dist_draw_params(v_cast, scene);
	find_draw_params(&draw_params, scene, nearest_cast(h_cast, v_cast));
	draw_sky(&draw_params, sdl_staff->surface);
	if (draw_params.cast->wall_type != -1)
		draw_wall(&draw_params, sdl_staff);
	draw_floor(&draw_params, sdl_staff->surface);
}
