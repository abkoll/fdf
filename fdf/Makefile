# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akoller <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 16:27:58 by akoller           #+#    #+#              #
#    Updated: 2018/01/18 23:17:10 by akoller          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

FLAGS	= -Wall -Wextra -Werror

SRCS	= fdf_main.c\
		  fdf_parse.c\
		  fdf_map.c\
		  fdf_environment.c\
		  fdf_window.c

OBJF	= $(SRCS:%.c=%.o)

INC		= includes/

LIBS	= src/libft/libft.a\
		  src/libmlx/libmlx.a

FRAMEWORKS	= -framework OpenGL -framework AppKit

all:	$(NAME)
	@gcc $(FLAGS) -o $(NAME) $(SRCS) -I$(INC) $(LIBS) $(FRAMEWORKS)

$(NAME):
	@make -C src/libft
	@make -C src/libmlx

clean:
	@/bin/rm -f rm $(OFILES)
	@make -C src/libft/ clean
	@make -C src/libmlx/ clean

fclean: clean
	@rm -f rm $(NAME)
	@make -C src/libft/ fclean
	@make -C src/libmlx/ fclean

re:	fclean all
