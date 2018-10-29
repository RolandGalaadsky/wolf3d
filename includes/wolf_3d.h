/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 15:17:13 by iradchen          #+#    #+#             */
/*   Updated: 2018/06/15 15:17:15 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_3D_H
# define WOLF_3D_H

# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"
# include "SDL.h"
# include <math.h>
# include <float.h>
# define PROJ_WIDTH 800
# define PROJ_HEIGHT 600
# define DIST_TO_PROJ_PLANE 693
# define BLOCK_SIZE 64
# define WINDOW_NAME "wolf3d"
# define TRUE 1
# define FALSE 0
# define RADIAN (0.017453)
# define S 1
# define H 0
# define V 1
# define X 0
# define Y 1
# define W 1
# define O 0
# define FOV 60
# define GET_ON_MAP(cord) (int)(cord / BLOCK_SIZE)
# define ZERO_CHECK(cord) (GET_ON_MAP(cord) >= 0 && cord > 0)
# define IS_IN(MAX, cord) (GET_ON_MAP(cord) < MAX && ZERO_CHECK(cord))
# define CH_ORT(scene, ort, pos) (IS_IN(scene->map_sizes[ort], pos[ort]))
# define VALID_CORD(pos, scene) (CH_ORT(scene, X, pos) && CH_ORT(scene, Y, pos))
# define PERIOD 360
# define H_DOWN 90
# define H_TOP 270
# define V_DOWN 180
# define V_TOP 359.9
# define VEC_2_SIZE 2 * sizeof(double)
# define TEX_NUM 10
# define WALL_NUM 11
# define SQ(x) ((x) * (x))

typedef struct		s_resources
{
	SDL_Surface	**textures;
}					t_resources;

typedef struct		s_sdl_staff
{
	SDL_Window		*window;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
	SDL_Renderer	*renderer;
	t_resources		*resources;
}					t_sdl_staff;

typedef struct		s_mv_params
{
	int				forward;
	int				back;
	double			speed;
}					t_mv_params;

typedef struct		s_rot_params
{
	int				left;
	int				right;
	double			speed;
}					t_rot_params;

typedef struct		s_player
{
	t_mv_params			*mv;
	t_rot_params		*rot;
	double				pov;
	double				angle_step;
	double				*pos;
}					t_player;

typedef struct		s_cast
{
	int				x_on_proj_plane;
	int				wall_type;
	int				type;
	double			angle;
	double			*pos;
	double			*dir;
	double			dist_to_inter;
}					t_cast;

typedef struct		s_draw_params
{
	int				height;
	int				end_y;
	int				begin_y;
	int				tex_pos_x;
	t_cast			*cast;
}					t_draw_params;

typedef struct		s_scene
{
	t_player		*player;
	int				**map;
	int				*map_sizes;
}					t_scene;

char				**resources_paths(int size);
double				*get_vec_2(double x, double y);

t_resources			*init_resources(char **path, int size);
void				free_resources(t_resources **resources);

void				free_sdl(t_sdl_staff **sdl_staff);
t_sdl_staff			*init_sdl(char *window_name);

void				input(int *quit, t_player *player);
void				draw(t_sdl_staff *sdl_staff, t_scene *scene);
void				set_pixel(SDL_Surface *surface, int x, int y, Uint32 color);
Uint32				get_pixel(SDL_Surface *surface, int x, int y);
Uint32				darker(Uint32 color, double k);

void				init_player(t_scene *scene, int x, int y);
void				update_player(t_scene *scene);
void				init_map(t_scene *scene, char **line, int fd);
t_scene				*init_scene(char *map_path);

void				set_cast(t_cast *cast, double angle, \
								t_player *player, double tang);
void				ray_cast(t_sdl_staff *sdl_staff, t_scene *scene);
void				del_common_params(t_cast *cast);
void				set_common_params(t_cast *cast, int type);
void				get_type_and_dist_draw_params(t_cast *cast, t_scene *scene);

void				draw_col(t_cast *h_cast, t_cast *v_cast, \
								t_scene *scene, t_sdl_staff *sdl_staff);
void				find_draw_params(t_draw_params *draw_params, \
											t_scene *scene, t_cast *cast);
t_cast				*nearest_cast(t_cast *h_cast, t_cast *v_cast);
Uint32				get_color(t_draw_params *draw_params, \
									int tex_pos_y, t_resources *resources);

void				error(char *message);
void				error_file(void);
void				check_malloc(void *ptr);

#endif
