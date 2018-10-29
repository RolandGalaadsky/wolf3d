# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iradchen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/18 17:53:45 by iradchen          #+#    #+#              #
#    Updated: 2017/11/18 18:41:22 by iradchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_strlen.c \
		ft_strdup.c \
		ft_strcpy.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strcmp.c \
		ft_strncmp.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_atoi.c \
		ft_memcmp.c \
		ft_strnew.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_putchar.c \
		ft_putstr.c \
		ft_putendl.c \
		ft_putnbr.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstnew.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstfold.c \
		ft_reduce_arr.c \
		ft_swap_int.c \
		ft_swap_str.c \
		ft_count_dig.c \
		ft_lstmap.c \
		ft_lstrev.c \
		get_next_line.c \

INCLUDES = -I includes

HDEP = includes/libft.h includes/get_next_line.h

CC = gcc

OBJ = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c $(HDEP)
	$(CC) -c -o $@ $< $(FLAGS) $(INCLUDES)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

.NOTPARALLEL: all clean fclean re