NAME = libftprintf.a

SRCS = ft_printf.c\

OBJS = ${SRCS:.C=o}

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o}

$(NAME): ${OBJS}
	ar rc $(NAME) ${OBJS}
	ranlib $(NAME)


all:	$(NAME)

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus
