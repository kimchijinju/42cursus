# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 14:47:12 by hanbkim           #+#    #+#              #
#    Updated: 2023/01/31 14:53:35 by hanbkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo
CFLAGS		= -Wextra -Wall -Werror

SRCS		= main.c init_argument.c birth_philosopher.c monitering.c \
			  who_is_died.c philosopher_do.c philosopher_check_status.c \
			  philosopher_take_fork.c  utils.c

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
