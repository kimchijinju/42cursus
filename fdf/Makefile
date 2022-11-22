# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 14:47:12 by hanbkim           #+#    #+#              #
#    Updated: 2022/11/22 16:50:46 by hanbkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf
CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code
MLXDIR	= ./lib/mlx
FTDIR	= ./lib/libft
HEADERS	= -I./includes -I./lib/mlx
LIBS	= -L$(MLXDIR) -lmlx -framework OpenGL -framework Appkit \
		  -L$(FTDIR) -lft
SRCS	= $(shell find ./srcs -iname "*.c")
OBJS	= $(SRCS:.c=.o)

all:
	@make libmlx
	@make libft
	@make $(NAME)

libmlx:
	@make -C $(MLXDIR)

libft:
	@make -C $(FTDIR)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)\n"

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) -o $(NAME)

clean:
	@rm -f $(OBJS)
	@make -C $(MLXDIR) clean
	@make -C $(FTDIR) clean

fclean:
	@make clean
	@rm -f $(NAME)

re:
	@make clean
	@make all

.PHONY: all, clean, fclean, re, libmlx, libft
