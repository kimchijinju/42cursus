# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanbkim <hanbkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 11:58:07 by hanbkim           #+#    #+#              #
#    Updated: 2022/10/21 13:00:48 by hanbkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = -rcs

INC = -I../../includes/

SRCS = $(shell find ./srcs -iname "*.c")

OBJS = $(SRCS:.c=.o)

NAME = libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	@$(CC) $(CFLAGS) $(INC) -c $^ -o $@

clean :
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean : 
	@make clean
	@rm -f $(NAME)

re :
	@make fclean
	@make all

.PHONY: all clean fclean re bonus libft
