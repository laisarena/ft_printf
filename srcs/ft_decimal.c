/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:50:53 by laisarena         #+#    #+#             */
/*   Updated: 2020/09/01 16:16:16 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void			ft_printnumberbase_fd(long long number,
											char *digitsbase, int fd)
{
	unsigned int base;

	base = ft_strlen(digitsbase);
	if (number >= base)
		ft_printnumberbase_fd(number / base, digitsbase, fd);
	ft_putchar_fd(digitsbase[number % base], fd);
}

static void			ft_printprefix_hexadecimal(t_flags flag)
{
	if (flag.hash && !flag.zeroexception.on)
	{
		if (flag.conversion == 'x' || flag.conversion == 'p')
			ft_putstr_fd("0x", 1);
		if (flag.conversion == 'X')
			ft_putstr_fd("0X", 1);
	}
	else if (flag.conversion == 'p')
		ft_putstr_fd("0x", 1);
}

static void			ft_printprefix_decimal(t_flags flag)
{
	if (flag.negative)
		ft_putchar_fd('-', 1);
	else if (flag.sign)
		ft_putchar_fd('+', 1);
	else if (flag.space)
		ft_putchar_fd(' ', 1);
}

static unsigned int	ft_analizezerocase(t_flags *flag)
{
	flag->zeroexception.on = 1;
	if (flag->prec.on && !flag->prec.val)
	{
		if (flag->width.val && !flag->sign && flag->conversion != 'p')
			flag->zeroexception.val = ' ';
		else
		{
			flag->zeroexception.val = 0;
			return (0);
		}
	}
	return (1);
}

static unsigned int	ft_countdigits(long long int number, unsigned int sizebase)
{
	unsigned int	digits;

	digits = 1;
	while (number >= sizebase && digits++)
		number = number / sizebase;
	return (digits);
}

static unsigned int	ft_numberdigits(t_flags *flag, long long int number,
										unsigned int sizebase)
{
	if ((int)number == 0)
		return (ft_analizezerocase(flag));
	return (ft_countdigits(number, sizebase));
}

t_function			ft_setdecimalfunctions(long long int (*correctsize)())
{
	t_function	function;

	function.correctsize = correctsize;
	function.numberdigits = ft_numberdigits;
	function.printprefix = ft_printprefix_decimal;
	function.printnumberbase = ft_printnumberbase_fd;
	function.base = "0123456789";
	function.sizebase = 10;
	return (function);
}

t_function			ft_sethexadecimalfunctions(char conversion,
										long long int (*correctsize)())
{
	t_function	function;

	function.correctsize = correctsize;
	function.numberdigits = ft_numberdigits;
	function.printprefix = ft_printprefix_hexadecimal;
	function.printnumberbase = ft_printnumberbase_fd;
	if (conversion == 'x' || conversion == 'p')
		function.base = "0123456789abcdef";
	else
		function.base = "0123456789ABCDEF";
	function.sizebase = 16;
	return (function);
}
