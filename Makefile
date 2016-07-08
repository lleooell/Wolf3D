#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eruffieu <eruffieu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/03 16:08:14 by eruffieu          #+#    #+#              #
#    Updated: 2015/01/23 08:41:55 by eruffieu         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

HEADER = wolf.h

SRC = main.c init_win.c iswall.c changedir.c inittab.c \
corner.c motion.c corner_two.c other.c other_two.c

SRCO = $(SRC:.c=.o)

LIB = ./libft/

MLX = -framework OpenGL -framework AppKit -L./minilibx_macos -lmlx

all : $(NAME)

$(NAME) :
	gcc -c -O3 -Wall -Werror -Wextra -lm $(MLX) $(SRC)
	cd $(LIB) ; make
	cd ./minilibx_macos ; make
	gcc -o $(NAME) $(HEADER) -Wall -Werror -Wextra -lm $(SRCO) -L./libft/ -lft $(MLX)

clean :
	rm -rf $(SRCO)
	cd $(LIB) ; make clean
	cd ./minilibx_macos/ ; make clean

fclean : clean
	rm -rf $(NAME)
	cd $(LIB) ; rm -rf libft.a
	cd ./minilibx_macos/ ; rm -rf libmlx.a

re : fclean $(NAME)

.PHONY : all clean fclean re
