# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 14:47:12 by hanbkim           #+#    #+#              #
#    Updated: 2022/11/28 13:41:43 by hanbkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
CFLAGS		= -g3 -fsanitize=address #-Wextra -Wall -Werror 
SRCS		= main.c atoi.c

OBJS		= $(SRCS:%.c=%.o)

all:
	@make $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< 

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	@rm -f $(OBJS)

fclean:
	@make clean
	@rm -f $(NAME)

re:
	@make clean
	@make all

.PHONY: all, clean, fclean, re
