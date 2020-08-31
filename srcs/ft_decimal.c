/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:50:53 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/31 16:04:49 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printNumberBase_fd(long long number, char *digitsbase, int fd)
{
	unsigned int base;

	base = ft_strlen(digitsbase);
	if (number >= base)
		ft_printNumberBase_fd(number / base, digitsbase, fd);
	ft_putchar_fd(digitsbase[number % base], fd);
}

static void	ft_printPrefix_hexadecimal(t_flags flag)
{
	if (flag.hasht && !flag.valueZero.on)
	{
		if (flag.conversion == 'x' || flag.conversion == 'p')
			ft_putstr_fd("0x", 1);
		if (flag.conversion == 'X')
			ft_putstr_fd("0X", 1);
	}
	else if (flag.hasht && flag.conversion == 'p')
		ft_putstr_fd("0x", 1);
}

static void	ft_printPrefix_decimal(t_flags flag)
{
	if (flag.negative)
		ft_putchar_fd('-',1);
	else if (flag.sign)
		ft_putchar_fd('+', 1);
	else if (flag.space) 
		ft_putchar_fd(' ', 1);
}

static void	ft_printAll(t_flags flag,
						long long value,
						t_function function)
{
	if (!flag.justify)
		while (flag.width.val--)
			if (!flag.zero)
				ft_putchar_fd(' ', 1);
	function.printPrefix(flag);
	while (flag.prec.val--)
		ft_putchar_fd('0', 1);
	if (!flag.valueZero.on)
		function.printNumberBase(value, function.base, 1);
	else if (flag.valueZero.val)
		ft_putchar_fd(flag.valueZero.val, 1);
	if (flag.justify)
		while (flag.width.val--)
			ft_putchar_fd(' ', 1);
}

/*
** PRECISION - the minimum number of digits to be printed for
**					d, i, o, u, x, and X conversions
**  - When '0' and precision, '0' is ignored.
**  - The sign of the number is not include on precision size
*/

static void	ft_calculatePadded(t_flags *flag,
								unsigned int len,
								unsigned int *nbr_pc)
{
	unsigned int	prefix;

	prefix = (flag->negative || flag->sign || flag->space) ? 1 : 0;
	prefix = (flag->hasht && !flag->valueZero.on) ? 2 : prefix;
	prefix = (flag->conversion == 'p') ? 2 : prefix;
	if (flag->prec.val > len)
		flag->prec.val -= len;
	else
		flag->prec.val = 0;
	if (flag->width.val > len + prefix + flag->prec.val)
		flag->width.val += -len - prefix - flag->prec.val;
	else
		flag->width.val = 0;
	*nbr_pc += flag->width.val + flag->prec.val + prefix + len; 
	if (flag->zero && !flag->justify)
		flag->prec.val += flag->width.val;

}

static int	ft_countDigits(long long int number, unsigned int sizeBase)
{
	unsigned int	digits;

	digits = 1;
	while (number >= sizeBase)
	{
		number = number / sizeBase;
		digits++;
	}
	return (digits);

}

static unsigned int ft_analizeZeroCase(t_flags *flag)
{
	flag->valueZero.on = 1;
	if (flag->prec.on && !flag->prec.val)
	{
		if (flag->width.val && !flag->sign && flag->conversion != 'p')
			flag->valueZero.val = ' ';
		else
		{
			flag->valueZero.val = 0;
			return (0);
		}
	}
	return (1);
}

long long int ft_correctSize_signedDecimal(t_flags *flag, long long int number)
{
	if (flag->ll)
		number = (long long int)number;
	else if (flag->l)
		number = (long int)number;
	else if (flag->h)
		number = (short int)number;
	else if (flag->hh)
		number = (signed char)number;
	else
		number = (int)number;
	flag->negative = (number < 0) ? 1 : 0;
	if ( number < 0)
		number = -number;
	return (number);
}

long long int ft_correctSize_unsignedDecimal(t_flags *flag, long long int number)
{
	if (flag->ll || flag->conversion == 'p')
		number = (unsigned long long int)number;
	else if (flag->l)
		number = (unsigned long int)number;
	else if (flag->h)
		number = (unsigned short int)number;
	else if (flag->hh)
		number = (unsigned char)number;
	else
		number = (unsigned int)number;
	return (number);
}

void		ft_setFunction_decimal(t_function *function, 
					long long int (*correctSize)())
{
	function->correctSize = correctSize;
	function->countDigits= ft_countDigits;
	function->printPrefix = ft_printPrefix_decimal;
	function->printNumberBase = ft_printNumberBase_fd;
	function->base = "0123456789";
	function->sizeBase = 10;
}

void		ft_setFunction_hexadecimal(t_function *function, char conversion)
{
	function->correctSize = ft_correctSize_unsignedDecimal;
	function->countDigits= ft_countDigits;
	function->printPrefix = ft_printPrefix_hexadecimal;
	function->printNumberBase = ft_printNumberBase_fd;
	if (conversion == 'x' || conversion == 'p')
		function->base = "0123456789abcdef";
	else
		function->base = "0123456789ABCDEF";
	function->sizeBase = 16;
}

void		ft_number(va_list args,
						t_flags flag,
						unsigned int *nbr_pc)
{
	t_function		function;
	long long int	number;
	unsigned int	digits;
	
	if (flag.conversion == 'd' || flag.conversion == 'i')
		ft_setFunction_decimal(&function, &ft_correctSize_signedDecimal);
	if (flag.conversion == 'u')
		ft_setFunction_decimal(&function, &ft_correctSize_unsignedDecimal);
	if (flag.conversion == 'x' || flag.conversion == 'X' ||
		flag.conversion == 'p')
		ft_setFunction_hexadecimal(&function, flag.conversion);
	if (flag.conversion == 'p')
		flag.hasht = 1;
	number = function.correctSize(&flag, va_arg(args,long long int));
	digits = function.countDigits(number, function.sizeBase);
	if ((int)number == 0)
		digits = ft_analizeZeroCase(&flag);
	ft_calculatePadded(&flag, digits, nbr_pc);
	ft_printAll(flag, number, function);
}
