# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laisarena <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/13 16:46:22 by laisarena         #+#    #+#              #
#    Updated: 2020/08/13 17:08:26 by laisarena        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

PATH_INCLUDE = ./includes

PATH_LIBFT = ./libft

PATH_SRCS = ./srcs/

SRCS = ft_printf.c\
	ft_c.c\
	ft_s.c\

OBJS = $(addprefix $(PATH_SRCS),$(SRCS:.c=.o))


#OBJS = ${SRCS:.c=.o}

.c.o:
	gcc -Wall -Wextra -Werror -c $< -o ${<:.c=.o} -I$(PATH_INCLUDE) 

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
	gcc -Wall -Wextra -Werror ./testes/*.c -L. -lftprintf  -L$(PATH_LIBFT) -lft -I$(PATH_INCLUDE) && ./a.out
testg:
	gcc -g -Wall -Wextra -Werror ./testes/*.c ft_printf.c -L. -lftprintf -L$(PATH_LIBFT) -lft -I$(PATH_INCLUDE) && ./a.out

.PHONY: all clean fclean re
