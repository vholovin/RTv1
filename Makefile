# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vholovin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/07/09 11:36:50 by vholovin          #+#    #+#              #
#    Updated: 2017/10/16 16:20:15 by vholovin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= RTv1
NAME_dSYM	= $(NAME:=.dSYM)

CC			= gcc
FLAG		= -Wall -Wextra -Werror -O2 -pipe -pedantic
FRAMEWORK	= -lmlx -framework OpenGL -framework AppKit
LOCAL		= -I minilibX -g -L minilibX
PTHREAD     = -lpthread
LIBFT		= libft/libft.a

SRC			= src/main.c			\
			src/init_rtv1_1.c		\
			src/init_rtv1_2.c		\
			src/read_file.c			\
			src/set_param.c			\
			src/set_check_scene.c	\
			src/add_object.c		\
			src/ft_ray_trace.c		\
			src/ft_vector.c			\
			src/ft_cross_object.c	\
			src/ft_cross_shadow.c	\
			src/ft_lambert.c		\
			src/ft_fong.c			\
			src/expose_hook.c		\
			src/key_press_hook.c	\
			src/rotate_object.c		\
			src/set_camera.c		\
			src/error.c				\
			src/ft_free.c			\
			src/esc.c				\
			src/tutorial.c

OBJ			= $(patsubst src/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(FLAG) -c $< -o $@
	printf '\033[31m ✔  %s\n\033[0m' "$<"

$(NAME): $(OBJ)
	make -C libft/
	$(CC) $(FLAG) $(LIBFT) $(LOCAL) $(FRAMEWORK) $(PTHREAD) $(OBJ) -o $(NAME)
	printf '\033[32m ✔  %s\n\033[0m' "Create RTv1"

clean:
	make -C libft/ clean
	rm -f $(OBJ)
	rm -f $(NAME_dSYM)
	printf '\033[33m ✔  %s\n\033[0m' "Clean RTv1"

fclean: clean
	make -C libft/ fclean
	rm -rf obj
	rm -f $(NAME)
	printf '\033[33m ✔  %s\n\033[0m' "Fclean RTv1"

re: fclean all

all: $(NAME)
.PHONY: clean fclean re all
