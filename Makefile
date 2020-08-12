NAME = libftprintf.a

PATH_LIBFT = ./libft

SRCS = ft_printf.c\

OBJS = ${SRCS:.c=.o}

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o} -I$(PATH_LIBFT) 

$(NAME): ${OBJS}
	make -C $(PATH_LIBFT)
	ar rc $(NAME) ${OBJS}
	ranlib $(NAME)

all:	$(NAME)


clean:
	make clean -C $(PATH_LIBFT)
	rm -f ${OBJS}

fclean: clean
	make fclean -C $(PATH_LIBFT)
	rm -f $(NAME)

re:	fclean all

test:
	gcc -Wall -Wextra -Werror main.c -L. -lftprintf -I. -L$(PATH_LIBFT) -lft -I$(PATH_LIBFT) && ./a.out

.PHONY: all clean fclean re
