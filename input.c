/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:13:14 by iradchen          #+#    #+#             */
/*   Updated: 2018/06/15 18:13:15 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

void	down(int *quit, t_player *player, SDL_Event e)
{
	if (e.key.keysym.sym == SDLK_UP)
		player->mv->forward = TRUE;
	if (e.key.keysym.sym == SDLK_DOWN)
		player->mv->back = TRUE;
	if (e.key.keysym.sym == SDLK_RIGHT)
		player->rot->right = TRUE;
	if (e.key.keysym.sym == SDLK_LEFT)
		player->rot->left = TRUE;
	if (e.key.keysym.sym == SDLK_LSHIFT)
		player->mv->speed *= 2;
	if (e.key.keysym.sym == SDLK_ESCAPE)
		*quit = TRUE;
}

void	up(t_player *player, SDL_Event e)
{
	if (e.key.keysym.sym == SDLK_UP)
		player->mv->forward = FALSE;
	if (e.key.keysym.sym == SDLK_DOWN)
		player->mv->back = FALSE;
	if (e.key.keysym.sym == SDLK_RIGHT)
		player->rot->right = FALSE;
	if (e.key.keysym.sym == SDLK_LEFT)
		player->rot->left = FALSE;
	if (e.key.keysym.sym == SDLK_LSHIFT)
		player->mv->speed /= 2;
}

void	input(int *quit, t_player *player)
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			*quit = TRUE;
		if (e.type == SDL_KEYDOWN)
			down(quit, player, e);
		else if (e.type == SDL_KEYUP)
			up(player, e);
	}
}
