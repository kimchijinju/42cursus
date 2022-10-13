# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 18:20:22 by hanbkim           #+#    #+#              #
#    Updated: 2022/10/04 16:16:02 by hanbkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

NAME = pipex

SRCS = ./gnl/get_next_line.c ./gnl/get_next_line_utils.c main.c 

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS) 	
	@make -C ./libft/ all
	$(CC) $(CFLAGS) -L./libft -lft $^ -o $@

%.o : %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean :
	@make -C ./libft/ clean
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean : 
	make clean
	@make -C ./libft/ fclean
	@rm -f $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re bonus
