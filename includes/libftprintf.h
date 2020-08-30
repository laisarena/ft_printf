/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 13:19:50 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/29 19:41:43 by laisarena        ###   ########.fr       */
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
	unsigned int	zero;
	unsigned int	justify;
	unsigned int	sign;
	unsigned int	space;
	unsigned int	hasht;
	unsigned int	l;
	unsigned int	ll;
	unsigned int	h;
	unsigned int	hh;
	t_flag_val		width;
	t_flag_val		prec;
	t_flag_val		valueZero;
}					t_flags;

int					ft_printf(const char *format, ...);
t_flags				ft_treatformatting(char *strflag, va_list args);
void				ft_c(va_list args, t_flags flag, unsigned int *nbr_pc);
void				ft_s(const char *str, t_flags flag, unsigned int *nbr_pc);
void				ft_p(va_list args, t_flags flag, unsigned int *nbr_pc);
void				ft_integers(va_list args, t_flags flag, unsigned int *nbr_p,
								char conversion);
void				ft_decimal(va_list args, t_flags flag, unsigned int *nbr_p);
#endif
