/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:02:42 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/13 17:07:25 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_setflags(t_flags *flag)
{
	flag->justify = 0;
	flag->width = 0;
	flag->precision = 0;
}

t_flags	ft_checkflag(char *strflag, va_list args)
{
	t_flags flag;

	ft_setflags(&flag);
	if (*strflag == '-')
	{
		flag.justify = 1;
		strflag++;
	}
	if (*strflag == '*')
	{
		flag.width = va_arg(args, int);
		strflag++;
	}
	while (ft_isdigit(*strflag))
	{
		flag.width = flag.width * 10 + *strflag - '0';
		strflag++;
	}
	return (flag);
}

static int	ft_isconversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i')
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

int	ft_printarg(const char *format, va_list args)
{
	int position;
	t_flags flag;

	if (!(position = ft_conversionposition(format++)))
		return (0);
	flag = ft_checkflag(ft_substr(format, 0, position), args);
	format += position - 1;
	if (*format == 'c')
		ft_c(args, flag);
	if (*format == 's')
		ft_s(args, flag);
	if (*format == 'p')
		return (0);
	if (*format == 'd')
		return (0);
	if (*format == 'i')
		return (0);
	return (position);
}

int	ft_printf(const char *format, ...)
{
	int	position;
	va_list	args;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			if (!(position = ft_printarg(format, args)))
				return (0);
			format += position;
		}
		else
			ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (0);
}
