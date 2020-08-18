/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 13:19:50 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/18 13:35:43 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"

typedef	struct
{
	unsigned int	zero;
	unsigned int	justify;
	unsigned int	width;
	unsigned int	precision;
	unsigned int	zprecision;
}					t_flags;
int					ft_printf(const char *format, ...);
t_flags				ft_checkflag(char *strflag, va_list args);
void				ft_c(va_list args, t_flags flag, unsigned int *nbr_pc);
void				ft_s(va_list args, t_flags flag, unsigned int *nbr_pc);
void				ft_integers(va_list args, t_flags flag, unsigned int *nbr_p,
								char conversion);

#endif
