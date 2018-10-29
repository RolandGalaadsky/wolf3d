/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:18:12 by iradchen          #+#    #+#             */
/*   Updated: 2018/06/15 14:18:13 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf_3d.h"
#define HEIGHT_ERR "error height"
#define WIDTH_ERR "error width"
#define WALL_ERR "error wall"
#define PLAYER_ERR "error player"

void	right_size(int cord, int size, char *mesage)
{
	if (cord != size || cord == 0)
		error(mesage);
}

int		player_error(int p_num, char *line)
{
	if (p_num || (*(line + 1) != ' ' && *(line + 1) != '\t' && *(line + 1)))
		error(PLAYER_ERR);
	return (1);
}

void	get_int_line(char *line, int *map, t_scene *scene, int y)
{
	int			x;
	static int	p_num = 0;

	x = 0;
	while (*line)
	{
		while (*line == ' ' || *line == '\t')
			line++;
		if (*line == 'x')
		{
			p_num = player_error(p_num, line);
			init_player(scene, x, y);
		}
		else if (!ft_isdigit(*line))
			error(WALL_ERR);
		if (x >= scene->map_sizes[X])
			error(WIDTH_ERR);
		map[x] = ft_atoi(line);
		while (*line != ' ' && *line && *line != '\t')
			line++;
		if (map[x] < 0 || map[x] > WALL_NUM)
			error(WALL_ERR);
		x++;
	}
	right_size(x, scene->map_sizes[X], WIDTH_ERR);
}

void	init_map(t_scene *scene, char **line, int fd)
{
	int		**map;
	int		y;
	int		er;

	map = (int **)ft_memalloc(sizeof(int *) * scene->map_sizes[Y]);
	check_malloc(map);
	y = 0;
	while ((er = get_next_line(fd, line)) > 0)
	{
		if (y >= scene->map_sizes[Y])
			error(HEIGHT_ERR);
		map[y] = (int *)ft_memalloc(sizeof(int) * scene->map_sizes[X]);
		check_malloc(map[y]);
		get_int_line(*line, map[y], scene, y);
		ft_strdel(line);
		y++;
	}
	ft_strdel(line);
	right_size(y, scene->map_sizes[Y], HEIGHT_ERR);
	if (er < 0)
		error_file();
	if (!scene->player)
		error(PLAYER_ERR);
	close(fd);
	scene->map = map;
}
