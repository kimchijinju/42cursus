# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanbkim <hanbkim@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/02 12:00:37 by hanbkim           #+#    #+#              #
#    Updated: 2022/10/13 16:28:29 by hanbkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rcs

CLIENT_NAME = client
SERVER_NAME = server

SERVER_SRCS = ./server.c 
CLIENT_SRCS = ./client.c 

SERVER_OBJS = $(SERVER_SRCS:.c=.o)
CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all :
	make client_mandatory
	make server_mandatory

server_mandatory : $(SERVER_NAME)

client_mandatory : $(CLIENT_NAME)

$(SERVER_NAME) : $(SERVER_OBJS)
	@make -C ./libft all
	$(CC) $(CFLAGS) $^ -L ./libft -lft -o $@

$(CLIENT_NAME) : $(CLIENT_OBJS)
	@make -C ./libft all
	$(CC) $(CFLAGS) $^ -L ./libft -lft -o $@

clean :
	@make -C ./libft clean
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)

fclean : 
	@make -C ./libft fclean
	@make clean
	rm -f $(SERVER_NAME) $(CLIENT_NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re client_mandatory server_mandatory
