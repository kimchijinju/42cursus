CC = c++
CFLAGS = -Wall -Wextra -Werror

SRCS = megaphone.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = megaphone

all : $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $^

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -f $(OBJS)

fclean :
	make clean
	rm -f $(NAME)

re:
	make clean
	make all

.PHONY: all, clean, fclean, re