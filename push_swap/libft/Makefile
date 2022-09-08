CC = cc
CFLAGS = -Wall -Wextra -Werror

AR = ar
ARFLAGS = -rcs

NAME = libft.a

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c \
	   ft_isalpha.c ft_isdigit.c ft_isalnum.c \
	   ft_isascii.c ft_isprint.c  ft_itoa.c \
	   ft_memchr.c ft_memcmp.c ft_memcpy.c \
	   ft_memmove.c ft_memset.c  \
	   ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	   ft_putstr_fd.c ft_split.c ft_strchr.c \
	   ft_strdup.c ft_striteri.c ft_strjoin.c \
	   ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	   ft_strmapi.c ft_strncmp.c ft_strnstr.c \
	   ft_strrchr.c ft_strtrim.c ft_substr.c \
	   ft_tolower.c ft_toupper.c \
	   
BONUS_SRCS = ft_lstsize.c ft_lstlast.c ft_lstlast.c \
			 ft_lstiter.c ft_lstdelone.c ft_lstclear.c \
			 ft_lstadd_back.c ft_lstmap.c ft_lstadd_front.c ft_lstnew.c \

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(BONUS_SRCS:.c=.o)

all : $(NAME)

bonus : $(NAME)

$(NAME) : $(OBJS) $(if $(filter bonus,$(MAKECMDGOALS)), $(OBJS_BONUS))
	@$(AR) $(ARFLAGS) $@ $^

%.o : %.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean :
	@rm -f $(OBJS) $(OBJS_BONUS)

fclean : clean
	@rm -f $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re bonus
