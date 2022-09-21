# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanbkim <hanbkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/01 13:48:26 by hanbkim           #+#    #+#              #
#    Updated: 2022/09/21 14:51:32 by hanbkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

MANDTORY_DIR = ./mandatory/
CMD_DIR = $(MANDTORY_DIR)command/
DQ_DIR = $(MANDTORY_DIR)deque/
SORT_DIR = $(MANDTORY_DIR)sort/

SRCS = $(MANDTORY_DIR)parse.c $(MANDTORY_DIR)main.c $(MANDTORY_DIR)error.c \
	   $(DQ_DIR)deque_command1.c $(DQ_DIR)deque_command2.c \
	   $(DQ_DIR)deque_create.c $(DQ_DIR)deque_get_value.c \
	   $(CMD_DIR)swap.c $(CMD_DIR)push.c \
	   $(CMD_DIR)rotate.c $(CMD_DIR)reverse_rotate.c \
	   $(SORT_DIR)get_location.c $(SORT_DIR)partitioning.c \
	   $(SORT_DIR)rotate_deque.c $(SORT_DIR)sort.c
OBJS = $(SRCS:%.c=%.o)

BONUS_DIR = ./bonus/
BCMD_DIR = $(BONUS_DIR)command/
BDQ_DIR = $(BONUS_DIR)deque/

SRCS_BONUS = $(BONUS_DIR)parse.c $(BONUS_DIR)main.c \
			 $(BONUS_DIR)error.c $(BONUS_DIR)get_command.c \
			 $(BDQ_DIR)deque_command1.c $(BDQ_DIR)deque_command2.c \
			 $(BDQ_DIR)deque_create.c $(BDQ_DIR)deque_get_value.c \
	   		 $(BCMD_DIR)swap.c $(BCMD_DIR)push.c \
	   		 $(BCMD_DIR)rotate.c $(BCMD_DIR)reverse_rotate.c \
			 $(BONUS_DIR)gnl/get_next_line.c $(BONUS_DIR)gnl/get_next_line_utils.c

OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

INCLUDES = -I./includes/

LIB = -L./libft/ -lft
NAME = push_swap
BONUS_NAME = checker

all : $(NAME)

bonus : $(BONUS_NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@ $(INCLUDES)

$(NAME) : $(OBJS)
	@make -C ./libft all
	$(CC) $(CFLAGS) $^ -o $@ $(INCLUDES) $(LIB) 

$(BONUS_NAME) : $(OBJS_BONUS)
	@make -C ./libft all
	$(CC) $(CFLAGS) $^ -o $@ $(INCLUDES) $(LIB)

clean :
	@make -C ./libft clean
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	@make -C ./libft fclean
	rm -rf $(NAME) $(BONUS_NAME)

re :
	make fclean
	make all
	make bonus

.PHONY: all clean fclean re
