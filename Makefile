# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iradchen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/15 16:10:32 by iradchen          #+#    #+#              #
#    Updated: 2018/06/15 16:10:34 by iradchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

SRCS =  errors.c \
		main.c \
		resources.c \
		sdl_staff.c \
		draw.c \
		input.c \
		game_params/init_map.c \
		game_params/init_scene.c \
		game_params/player.c \
		ray_cast/ray_cast.c \
		ray_cast/ray_cast_tools.c \
		get_vec_2.c \
		game_params/update_player.c \
		ray_cast/common_cast_fun.c \
		ray_cast/draw_col.c \
		ray_cast/draw_col_tools.c \
		color_tools.c
		
OBJ = $(SRCS:%.c=%.o)

CC = gcc

HDEP = includes/wolf_3d.h

LIBS = -L libft/ -lft -framework SDL2 -F ./Frameworks/

INCLUDES = -I libft/includes -I includes/ -I Frameworks/SDL2.framework/Headers/

SDL2_P = -rpath @loader_path/Frameworks/

FLAGS = -Wall -Wextra -Werror $(INCLUDES)

%.o: %.c $(HDEP)
	$(CC) -c -o $@ $< $(FLAGS)

all: $(NAME)

$(NAME) : $(OBJ)
	@make -C libft
	@$(CC) $(FLAGS) $(OBJ) $(SDL2_P) $(LIBS) -o $(NAME)

clean:
	@make -C libft/ clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re
