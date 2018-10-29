/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_staff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:27:44 by iradchen          #+#    #+#             */
/*   Updated: 2018/06/15 18:27:51 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"
#define FAIL_VIDEO "Error: Can't init video"
#define FAIL_WINDOW "Error: Can't create window"

void		free_sdl(t_sdl_staff **sdl_staff)
{
	SDL_DestroyTexture((*sdl_staff)->texture);
	SDL_FreeSurface((*sdl_staff)->surface);
	SDL_DestroyRenderer((*sdl_staff)->renderer);
	SDL_DestroyWindow((*sdl_staff)->window);
	ft_memdel((void **)sdl_staff);
}

t_sdl_staff	*init_sdl(char *window_name)
{
	t_sdl_staff	*sdl_staff;

	sdl_staff = (t_sdl_staff *)ft_memalloc(sizeof(t_sdl_staff));
	check_malloc(sdl_staff);
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_putendl(FAIL_VIDEO);
	sdl_staff->window = SDL_CreateWindow(
		window_name,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		PROJ_WIDTH,
		PROJ_HEIGHT,
		SDL_WINDOW_OPENGL);
	sdl_staff->texture = NULL;
	sdl_staff->surface = SDL_CreateRGBSurfaceWithFormat(0, PROJ_WIDTH, \
		PROJ_HEIGHT, 32, SDL_PIXELFORMAT_RGB888);
	if (sdl_staff->window == NULL)
		ft_putendl(FAIL_WINDOW);
	sdl_staff->renderer = SDL_CreateRenderer(sdl_staff->window, -1, 0);
	return (sdl_staff);
}
