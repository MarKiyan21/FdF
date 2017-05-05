#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkyianyt <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/17 19:25:28 by mkyianyt          #+#    #+#              #
#    Updated: 2017/02/18 13:48:58 by mkyianyt         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
NAME = fdf

SRC = fdf_centremap.c fdf_check_valid.c fdf_draw_line.c fdf_free.c \
	  fdf_init_map.c fdf_key_setting.c fdf_main.c fdf_map.c fdf_mapcpy.c \
	  fdf_read_map.c fdf_rotation.c fdf_scale_points.c

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra

ATTACH = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	gcc $(CFLAGS) -o $(NAME) -L libft -lft $(OBJ) $(ATTACH)

.c.o:
	gcc $(CFLAGS) -c $< -o $@ \

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRC)