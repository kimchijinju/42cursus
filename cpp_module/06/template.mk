.DEFAULT_GOAL = all

CXX = c++

ifndef CXXFLAGS
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
endif
CPPFLAGS = -MMD -MP

ifndef NAME
NAME = a.out
endif

OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

-include $(DEPS)

all : $(NAME)

%.o : %.cpp
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $^

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -o $@ $^

clean :
	rm -f $(OBJS) $(wildcard *.d) $(wildcard *.gch)

fclean :
	make clean
	rm -f $(NAME)

re:
	make clean
	make all

.PHONY: all, clean, fclean, re
