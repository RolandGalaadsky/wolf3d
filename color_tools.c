/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:08:10 by iradchen          #+#    #+#             */
/*   Updated: 2018/06/15 18:08:11 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"
#define GET_RED(x) (x >> 16)
#define GET_GREEN(x) ((x >> 8) & 0xff)
#define GET_BLUE(x) (x & 0xff)
#define DO_RGB(r, g, b) ((clip(r) << 16) | (clip(g) << 8) | clip(b))

int		clip(int color)
{
	if (color > 0xff)
		return (0xff);
	if (color < 0)
		return (0);
	return (color);
}

void	set_pixel(SDL_Surface *surface, int x, int y, Uint32 color)
{
	Uint32 *target_pixel;

	target_pixel = surface->pixels + y * surface->pitch + \
	x * sizeof(Uint32);
	*target_pixel = color;
}

Uint32	darker(Uint32 color, double k)
{
	Uint8 r;
	Uint8 g;
	Uint8 b;

	r = (Uint8)((double)k * GET_RED(color));
	g = (Uint8)((double)k * GET_GREEN(color));
	b = (Uint8)((double)k * GET_BLUE(color));
	return (DO_RGB(r, g, b));
}

Uint32	get_pixel(SDL_Surface *surface, int x, int y)
{
	Uint32 *target_pixel;

	target_pixel = surface->pixels + y * surface->pitch + \
	x * sizeof(Uint32);
	return (*target_pixel);
}
