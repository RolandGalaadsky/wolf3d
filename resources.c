/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resources.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 18:25:04 by iradchen          #+#    #+#             */
/*   Updated: 2018/06/15 18:25:05 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"
#define TEX_ERROR "can't load texture."

SDL_Surface	*init_texture(char *path)
{
	SDL_Surface	*image;
	SDL_Surface	*surf;

	image = SDL_LoadBMP(path);
	if (!image)
		error(TEX_ERROR);
	surf = SDL_ConvertSurfaceFormat(image, SDL_PIXELFORMAT_RGB888, 0);
	if (!surf)
		error(TEX_ERROR);
	SDL_FreeSurface(image);
	return (surf);
}

char		**resources_paths(int size)
{
	char	*buff;
	char	**path;
	int		i;

	path = (char **)ft_memalloc(size * sizeof(char *));
	check_malloc(path);
	i = 0;
	while (i < size)
	{
		buff = ft_itoa(i);
		path[i] = ft_strjoin("textures/", buff);
		ft_strdel(&buff);
		buff = ft_strjoin(path[i], ".bmp");
		ft_strdel(&path[i]);
		path[i] = buff;
		i++;
	}
	return (path);
}

t_resources	*init_resources(char **path, int size)
{
	t_resources *resources;
	int			i;

	resources = (t_resources *)ft_memalloc(sizeof(t_resources));
	check_malloc(resources);
	resources->textures = (SDL_Surface **)ft_memalloc(size * \
		sizeof(SDL_Surface *));
	check_malloc(resources->textures);
	i = 0;
	while (i < size)
	{
		resources->textures[i] = init_texture(path[i]);
		i++;
	}
	return (resources);
}

void		free_resources(t_resources **resources)
{
	int i;

	i = 0;
	while (i < TEX_NUM)
	{
		SDL_FreeSurface((*resources)->textures[i]);
		i++;
	}
	ft_memdel((void **)&(*resources)->textures);
	ft_memdel((void **)resources);
}
