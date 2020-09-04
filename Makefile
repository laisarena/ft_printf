# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/13 16:46:22 by lfrasson          #+#    #+#              #
#    Updated: 2020/09/04 13:29:25 by lfrasson         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

NAME_LIBFT = libft.a

PATH_INCLUDE = ./includes/

PATH_LIBFT = ./libft/

PATH_SRCS = ./srcs/

SRCS = ft_printf.c\
	   ft_flags.c\
	   ft_flagsaux.c\
	   ft_character.c\
	   ft_string.c\
	   ft_number.c\
	   ft_numberaux.c\
	   ft_printnumber.c\
	   ft_decimal.c\
	   ft_hexadecimal.c\

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

.PHONY: all clean fclean re
