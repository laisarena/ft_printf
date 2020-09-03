/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 13:19:50 by laisarena         #+#    #+#             */
/*   Updated: 2020/09/03 17:12:07 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef struct
{
	unsigned int	on;
	unsigned int	val;
}					t_flag_val;

typedef	struct
{
	unsigned int	conversion;
	unsigned int	zero;
	unsigned int	justify;
	unsigned int	sign;
	unsigned int	negative;
	unsigned int	space;
	unsigned int	hash;
	unsigned int	l;
	unsigned int	ll;
	unsigned int	h;
	unsigned int	hh;
	t_flag_val		width;
	t_flag_val		prec;
	t_flag_val		zeroexception;
}					t_flags;

typedef	struct
{
	unsigned int	sizebase;
	char			*base;
	long long int	(*correctsize)(t_flags *flag, long long int number);
	unsigned int	(*numberdigits)(t_flags *flag, long long int number,
										unsigned int sizebase);
	void			(*printprefix)(t_flags flag);
	void			(*printnumberbase)(long long int number,
										char *base, int fd);
}					t_function;

int					ft_printf(const char *format, ...);
t_flags				ft_treatformatting(char *strflag, va_list args);
char				*ft_width_precision(char *strflag, t_flags *flag,
										va_list args);
void				ft_character(unsigned int c, t_flags flag,
								unsigned int *totalprinted);
void				ft_string(const char *str, t_flags flag,
								unsigned int *totalprinted);
void				ft_integers(va_list args, t_flags flag,
								unsigned int *totalprinted, char conversion);
void				ft_number(va_list args, t_flags flag,
								unsigned int *totalprinted);
t_function			ft_setdecimalfunctions(long long int (*correctsize)());
t_function			ft_sethexafunctions(char conversion,
										long long int (*correctsize)());
void				ft_printall(t_flags flag, long long value,
								t_function function);
void				ft_calculatepadded(t_flags *flag, unsigned int len,
										unsigned int *totalprinted);
void				ft_printnumberbase_fd(long long number,
											char *digitsbase, int fd);
unsigned int		ft_numberdigits(t_flags *flag, long long int number,
										unsigned int sizebase);
#endif
