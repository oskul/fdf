# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oskulska <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/27 20:03:11 by oskulska          #+#    #+#              #
#    Updated: 2018/03/27 20:06:44 by oskulska         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

LIBFTDIR = libft/

SRC = 	main.c\
			fdf_color.c\
			fdf_draw.c\
			fdf_find_cord.c\
			fdf_key_hook.c\
			fdf_lib.c\
			fdf_move.c\
			fdf_read_map.c\

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

FLAGM = -lmlx -framework OpenGL -framework AppKit

all: $(NAME) 

$(NAME): $(OBJ) $(LIBFTDIR)libft.a
	$(CC) $(CFLAGS) $(FLAGM) $(OBJ) -o $(NAME) -L./$(LIBFTDIR) -lft -I fdf.h

$(LIBFTDIR)libft.a: libft/Makefile
	make -C $(LIBFTDIR)

%.o: %.c
		$(CC) $(CFLAGS) -o $@ -c $<
clean:
		rm -f $(OBJ)
		make clean -C $(LIBFTDIR)

fclean: clean
		rm -f $(NAME)
		rm -f $(LIBFTDIR)libft.a

re: fclean all

run: all
	@./fdf test_maps/42.fdf