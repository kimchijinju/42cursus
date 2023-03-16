CC = c++

ifndef CFLAGS
CFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP
endif

ifndef NAME
NAME = a.out
endif

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

-include $(DEPS)

all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $^

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -f $(OBJS)
	rm -f $(DEPS)

fclean :
	make clean
	rm -f $(NAME)

re:
	make clean
	make all

.PHONY: all, clean, fclean, re
