# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 13:48:26 by hanbkim           #+#    #+#              #
#    Updated: 2022/09/05 15:40:51 by hanbkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra -g3

SRCS = parse.c main.c deque.c
OBJS = $(SRCS:.c=.o)

NAME = push_swap

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C ./libft all
	$(CC) $(CFLAGS) $^ -o $@ -L./libft -lft

clean :
	@make -C ./libft clean
	rm -rf $(OBJS)

fclean : clean
	@make -C ./libft fclean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re
