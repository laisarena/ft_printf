/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 13:19:50 by laisarena         #+#    #+#             */
/*   Updated: 2020/09/01 16:04:13 by laisarena        ###   ########.fr       */
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
void				ft_character(va_list args,
									t_flags flag, unsigned int *nbr_pc);
void				ft_string(const char *str,
									t_flags flag, unsigned int *nbr_pc);
void				ft_p(va_list args, t_flags flag, unsigned int *nbr_pc);
void				ft_integers(va_list args, t_flags flag, unsigned int *nbr_p,
								char conversion);
void				ft_number(va_list args, t_flags flag, unsigned int *nbr_pc);
t_function			ft_setdecimalfunctions(long long int (*correctsize)());
t_function			ft_sethexadecimalfunctions(char conversion,
												long long int (*correctsize)());
#endif
