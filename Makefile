NAME = libftprintf.a

CC_FLAGS = -Wall -Wextra -Werror

SRCS =	ft_printf.c	ft_printf_utils.c	

INCLUDE = ft_printf.h

OBJS = $(SRCS:.c=.o)

all: $(NAME)
	make clean

$(NAME): $(OBJS) $(INCLUDE) 
	ar -rcs $(NAME) $(OBJS)

clean: 
	rm -f ${OBJS}

fclean: clean 
	rm -f $(NAME)

re: fclean all

bonus: all

update: 
	git pull

.PHONY: all clean fclean re bonus test