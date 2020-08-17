/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:02:42 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/17 16:28:28 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_isconversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
			c == 'x' || c == 'X')
		return (1);
	return (0);
}

static int	ft_conversionposition(const char *s)
{
	int position;

	position = 0;
	while (!(ft_isconversion((char)s[position])))
		if (s[position++] == '\0')
			return (0);
	return (position);
}

static int	ft_printarg(const char *format, va_list args, unsigned int *nbr_pc)
{
	int		position;
	t_flags	flag;

	if (!(position = ft_conversionposition(format++)))
		return (0);
	flag = ft_checkflag(ft_substr(format, 0, position), args);
	format += position - 1;
	if (*format == 'c')
		ft_c(args, flag, nbr_pc);
	if (*format == 's')
		ft_s(args, flag, nbr_pc);
	if (*format == 'p' || *format == 'd' || *format == 'i' || *format == 'u'
			|| *format == 'x' || *format == 'X')
		ft_integers(args, flag, nbr_pc, *format);
	return (position);
}

int			ft_printf(const char *format, ...)
{
	int				position;
	unsigned int	nbr_pc;
	va_list			args;

	nbr_pc = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (!(position = ft_printarg(format, args, &nbr_pc)))
				return (0);
			format += position;
		}
		else
		{
			ft_putchar_fd(*format, 1);
			nbr_pc++;
		}
		format++;
	}
	va_end(args);
	return (nbr_pc);
}
