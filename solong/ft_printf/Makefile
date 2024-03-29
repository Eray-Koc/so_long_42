NAME	=	libftprintf.a

SRCS	=	ft_printf.c ft_printf_funcz.c ft_printf_funcs.c

OBJS = $(SRCS:.c=.o)


CC	=	gcc
RM	=	rm -rf
FLAGS	= -Wall -Wextra -Werror

$(NAME): 
		$(CC) $(FLAGS) -c $(SRCS) 
		ar rc $(NAME) $(OBJS)


all: $(NAME)

clean:
		$(RM) $(OBJS) 

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re