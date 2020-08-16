# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laisarena <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/13 16:46:22 by laisarena         #+#    #+#              #
#    Updated: 2020/08/16 10:50:38 by laisarena        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PATH_INCLUDE = ./includes

PATH_LIBFT = ./libft

PATH_SRCS = ./srcs/

SRCS = ft_printf.c\
	ft_flags.c\
	ft_c.c\
	ft_s.c\
	ft_di.c\
	ft_integers.c\

OBJS = $(addprefix $(PATH_SRCS),$(SRCS:.c=.o))

FLAGS = -Wall -Wextra -Werror  

#OBJS = ${SRCS:.c=.o}

.c.o:
	gcc $(FLAGS) -c $< -o ${<:.c=.o} -I$(PATH_INCLUDE) 

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
	gcc $(FLAGS) ./testes/*.c -L. -lftprintf  -L$(PATH_LIBFT) -lft -I$(PATH_INCLUDE) && ./a.out
testg:
	gcc -g $(FLAGS) ./testes/*.c ./srcs/*.c -L. -lftprintf -L$(PATH_LIBFT) -lft -I$(PATH_INCLUDE) && ./a.out

testf:
	gcc  ./testes/*.c -L. -lftprintf  -L$(PATH_LIBFT) -lft -I$(PATH_INCLUDE) && ./a.out
.PHONY: all clean fclean re
