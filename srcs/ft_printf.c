/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:02:42 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/30 18:38:48 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_isconversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' ||
			c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	ft_conversionposition(const char *s)
{
	int position;

	position = 1;
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
	flag = ft_treatformatting(ft_substr(format, 0, position), args);
	format += position - 1;
	flag.conversion = *format;
	if (*format == '%')
		ft_s(ft_substr(format, 0, 1), flag, nbr_pc);
	if (*format == 'c')
		ft_c(args, flag, nbr_pc);
	if (*format == 's')
		ft_s(va_arg(args, char *), flag, nbr_pc);
	if (*format == 'p')
		ft_p(args, flag, nbr_pc);
	if (*format == 'd' || *format == 'i'|| *format == 'u' ||
			*format == 'x' || *format == 'X')
		ft_number(args, flag, nbr_pc);
		//ft_integers(args, flag, nbr_pc, *format);
	return (position);
}

int			ft_printf(const char *format, ...)
{
	unsigned int	nbr_pc;
	va_list			args;

	nbr_pc = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (!(format += ft_printarg(format, args, &nbr_pc)))
				return (0);
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
