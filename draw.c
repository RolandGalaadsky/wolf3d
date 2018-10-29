/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:06:58 by iradchen          #+#    #+#             */
/*   Updated: 2018/06/15 18:07:00 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"
#define BLACK 0

void	clear_surface(SDL_Surface *surface, int width, int height)
{
	int x;
	int y;

	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			set_pixel(surface, x, y, BLACK);
			y++;
		}
		x++;
	}
}

void	draw(t_sdl_staff *sdl_staff, t_scene *scene)
{
	clear_surface(sdl_staff->surface, PROJ_WIDTH, PROJ_HEIGHT);
	SDL_DestroyTexture(sdl_staff->texture);
	SDL_RenderClear(sdl_staff->renderer);
	ray_cast(sdl_staff, scene);
	sdl_staff->texture = SDL_CreateTextureFromSurface(sdl_staff->renderer, \
		sdl_staff->surface);
	SDL_RenderCopy(sdl_staff->renderer, sdl_staff->texture, NULL, NULL);
	SDL_RenderPresent(sdl_staff->renderer);
}
