/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:02:42 by laisarena         #+#    #+#             */
/*   Updated: 2020/09/02 14:16:14 by laisarena        ###   ########.fr       */
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

static const char	*ft_analizeconversion(const char *format, va_list args,
											unsigned int *totalprinted)
{
	int		position;
	t_flags	flag;

	if (!(position = ft_conversionposition(format++)))
		return (0);
	flag = ft_treatformatting(ft_substr(format, 0, position), args);
	format += position - 1;
	flag.conversion = *format;
	if (*format == '%')
		ft_string(ft_substr(format, 0, 1), flag, totalprinted);
	if (*format == 'c')
		ft_character(args, flag, totalprinted);
	if (*format == 's')
		ft_string(va_arg(args, char *), flag, totalprinted);
	if (*format == 'd' || *format == 'i' || *format == 'u' ||
		*format == 'x' || *format == 'X' || *format == 'p')
		ft_number(args, flag, totalprinted);
	return (format);
}

static void	ft_analizeformat(const char *format, va_list args,
								unsigned int *totalprinted)
{
	while (*format)
	{
		if (*format == '%')
			format = ft_analizeconversion(format, args, totalprinted) + 1;
		else
		{
			ft_putchar_fd(*format++, 1);
			(*totalprinted)++;
		}
	}
}

int			ft_printf(const char *format, ...)
{
	unsigned int	totalprinted;
	va_list			args;

	totalprinted = 0;
	va_start(args, format);
	ft_analizeformat(format, args, &totalprinted);
	va_end(args);
	return (totalprinted);
}
