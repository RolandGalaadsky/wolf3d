/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:14:17 by iradchen          #+#    #+#             */
/*   Updated: 2018/06/15 14:14:18 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"
#define ERR_MAP_SIZE "invalid map size"

int			get_map_size(char *line, t_scene *scene)
{
	int i;

	i = 0;
	scene->map_sizes = (int *)ft_memalloc(sizeof(int) * 2);
	check_malloc(scene->map_sizes);
	while (i < 2)
	{
		while (*line == ' ' || *line == '\t')
			line++;
		if (!ft_isdigit(*line))
			return (0);
		scene->map_sizes[i] = ft_atoi(line);
		if (scene->map_sizes[i] < 1 || scene->map_sizes[i] > 40)
			return (0);
		while (*line != ' ' && *line && *line != '\t')
			line++;
		i++;
	}
	return (1);
}

t_scene		*init_scene(char *map_path)
{
	t_scene		*scene;
	int			err;
	int			fd;
	char		*line;

	scene = (t_scene *)ft_memalloc(sizeof(t_scene));
	fd = open(map_path, O_RDONLY);
	err = get_next_line(fd, &line);
	if (err < 0)
		error_file();
	if (!get_map_size(line, scene))
		error(ERR_MAP_SIZE);
	ft_strdel(&line);
	init_map(scene, &line, fd);
	return (scene);
}
