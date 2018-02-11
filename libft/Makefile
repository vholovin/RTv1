# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vholovin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 16:49:22 by vholovin          #+#    #+#              #
#    Updated: 2017/08/08 16:22:10 by vholovin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

HEAD		= src/libft.h
HEAD_GCH	= src/libft.h.gch

CC			= gcc
FLAGS		= -Wall -Wextra -Werror -O2 -pipe

SRC			= src/ft_putchar.c	\
			src/ft_putchar_fd.c	\
			src/ft_putstr.c 	\
			src/ft_putstr_fd.c	\
			src/ft_putendl.c	\
			src/ft_putendl_fd.c	\
			src/ft_putnbr.c		\
			src/ft_putnbr_fd.c	\
			src/ft_memset.c		\
			src/ft_bzero.c		\
			src/ft_memcpy.c		\
			src/ft_memccpy.c	\
			src/ft_memmove.c	\
			src/ft_memchr.c		\
			src/ft_memcmp.c		\
			src/ft_strlen.c		\
			src/ft_strdup.c		\
			src/ft_strndup.c	\
			src/ft_strcpy.c		\
			src/ft_strncpy.c	\
			src/ft_strcat.c		\
			src/ft_strlcat.c	\
			src/ft_strncat.c	\
			src/ft_strchr.c		\
			src/ft_strrchr.c	\
			src/ft_strstr.c		\
			src/ft_strnstr.c	\
			src/ft_strcmp.c		\
			src/ft_strncmp.c	\
			src/ft_isalpha.c	\
			src/ft_isdigit.c	\
			src/ft_isalnum.c	\
			src/ft_isascii.c	\
			src/ft_isprint.c	\
			src/ft_toupper.c	\
			src/ft_tolower.c	\
			src/ft_lerpi.c		\
			src/ft_atoi.c		\
			src/ft_atoi_base.c	\
			src/ft_itoa.c		\
			src/ft_memalloc.c	\
			src/ft_memdel.c		\
			src/ft_strnew.c		\
			src/ft_strdel.c		\
			src/ft_strclr.c		\
			src/ft_striter.c	\
			src/ft_striteri.c	\
			src/ft_strmap.c		\
			src/ft_strmapi.c	\
			src/ft_strequ.c		\
			src/ft_strnequ.c	\
			src/ft_strsub.c		\
			src/ft_strjoin.c	\
			src/ft_strtrim.c	\
			src/ft_strsplit.c	\
			src/ft_lstnew.c		\
			src/ft_lstdelone.c	\
			src/ft_lstdel.c		\
			src/ft_lstdel.c		\
			src/ft_lstadd.c		\
			src/ft_lstiter.c	\
			src/ft_lstmap.c		\
			src/ft_is_prime.c	\
			src/ft_swap.c		\
			src/ft_sqrt.c		\
			src/ft_power.c		\
			src/ft_factorial.c	\
			src/ft_clamp.c		\
			src/get_next_line.c

OBJ		= $(patsubst src/%.c,obj/%.o,$(SRC))
.SILENT:

all: $(NAME)

obj/%.o: src/%.c
	mkdir -p obj
	$(CC) $(FLAG) -c $< -o $@
	printf '\033[31m ✔  %s\n\033[0m' "$<"


$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	printf '\033[32m ✔  %s\n\033[0m' "Create Libft"

clean:
	rm -rf $(OBJ)
	rm -f $(HEAD_GCH)
	printf '\033[33m ✔  %s\n\033[0m' "Clean Libft"

fclean: clean
	rm -rf obj
	rm -f $(NAME)
	printf '\033[33m ✔  %s\n\033[0m' "Fclean Libft"

re: fclean all

all: $(NAME)
.PHONY: clean fclean re all 
