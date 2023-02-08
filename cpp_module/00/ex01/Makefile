CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = contact.cpp phonebook.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = book

all : $(NAME)

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -c $^

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -f $(OBJS)
	rm -f *.gch

fclean :
	make clean
	rm -f $(NAME)

re:
	make clean
	make all

.PHONY: all, clean, fclean, re