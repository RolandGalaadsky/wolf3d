/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 13:30:22 by iradchen          #+#    #+#             */
/*   Updated: 2018/06/15 13:30:44 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"

void	usage(void)
{
	ft_putendl("usage: ./wolf3d [map_path]");
	ft_putendl("map is in format: ");
	ft_putendl("h w");
	ft_putendl("B00 ..... B0w-1");
	ft_putendl(".    .    .");
	ft_putendl(".     Bij .");
	ft_putendl(".      .  .");
	ft_putendl("Bh-10 ..... Bh-1w-1");
	ft_putstr("where h - height of the map, 0 < h <= 40");
	ft_putendl(", w - widht of the map, 0 < w <= 40");
	ft_putendl("Bij is in {0,..,11,x} 0 <= i < h, 0 <= j < w");
	ft_putendl("x is player");
	ft_putstr("number is box type ");
	ft_putendl("0 - no box, 11 - special box with differrent 4 sides");
	ft_putendl("to see other wall type look textures/(type - 1).bmp");
	ft_putendl("To move in the map use arrows, left shift to acceleration");
}

void	loop(t_sdl_staff *sdl_staff, t_scene *scene)
{
	int quit;

	quit = FALSE;
	while (!quit)
	{
		input(&quit, scene->player);
		update_player(scene);
		draw(sdl_staff, scene);
	}
}

void	free_paths(char ***resources, int size)
{
	char	**tex;
	int		i;

	i = 0;
	tex = *resources;
	while (i < size)
	{
		ft_strdel(tex + i);
		i++;
	}
	ft_memdel((void **)resources);
}

int		main(int ac, char **av)
{
	t_sdl_staff		*sdl_staff;
	t_resources		*resources;
	t_scene			*scene;
	char			**paths;

	if (ac < 2)
	{
		usage();
		return (1);
	}
	scene = init_scene(av[1]);
	sdl_staff = init_sdl(WINDOW_NAME);
	paths = resources_paths(TEX_NUM);
	resources = init_resources(paths, TEX_NUM);
	sdl_staff->resources = resources;
	free_paths(&paths, TEX_NUM);
	loop(sdl_staff, scene);
	free_resources(&resources);
	free_sdl(&sdl_staff);
	SDL_Quit();
	return (0);
}
