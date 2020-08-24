# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laisarena <marvin@42.fr>                   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/13 16:46:22 by laisarena         #+#    #+#              #
#    Updated: 2020/08/24 11:02:09 by laisarena        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

NAME_LIBFT = libft.a

PATH_INCLUDE = ./includes/

PATH_LIBFT = ./libft/

PATH_SRCS = ./srcs/

SRCS = ft_printf.c\
	ft_flags.c\
	ft_c.c\
	ft_s.c\
	ft_pointer.c\
	ft_integers.c\

OBJS = $(addprefix $(PATH_SRCS),$(SRCS:.c=.o))

FLAGS = -Wall -Wextra -Werror  

.c.o:
	gcc $(FLAGS) -I$(PATH_INCLUDE) -c $< -o ${<:.c=.o} 

$(NAME): ${OBJS}
	make -C $(PATH_LIBFT)
	cp $(PATH_LIBFT)$(NAME_LIBFT) $(NAME)
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
	gcc $(FLAGS) ../testePrintf/testes/*.c -L. -lftprintf  -L$(PATH_LIBFT) -lft -I$(PATH_INCLUDE) && ./a.out
testg:
	gcc -g $(FLAGS) ../testePrintf/testes/*.c ./srcs/*.c -L. -lftprintf -L$(PATH_LIBFT) -lft -I$(PATH_INCLUDE) && ./a.out

testf:
	gcc  ../testePrintf/testes/*.c -L. -lftprintf -I$(PATH_INCLUDE) && ./a.out
.PHONY: all clean fclean re
