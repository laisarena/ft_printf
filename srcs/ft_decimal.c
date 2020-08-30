/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:50:53 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/29 21:56:21 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printnumber_fd(long long number, int fd)
{
	if (number >= 10)
		ft_printnumber_fd(number / 10, fd);
	ft_putchar_fd(number % 10 + '0', fd);
}
/*static void	ft_printnumber_base_fd(long long number, char *digitsbase, int fd)
{
	unsigned int base;

	base = ft_strlen(digitsbase);
	if (number >= base)
		ft_printnumber_base_fd(number / base, digitsbase, fd);
	ft_putchar_fd(digitsbase[number % base], fd);
}*/
static void	ft_printPrefix(t_flags flag)
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
		ft_printnumber_fd(value, 1);
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

static int	ft_countDigits(long long int number, unsigned int base)
{
	unsigned int	digits;

	digits = 1;
	while (number >= base)
	{
		number = number / base;
		digits++;
	}
	return (digits);

}

static unsigned int ft_analizeZeroCase(t_flags *flag)
{
	flag->valueZero.on = 1;
	if (flag->prec.on && !flag->prec.val)
	{
		if (flag->width.val && !flag->sign)
			flag->valueZero.val = ' ';
		else
		{
			flag->valueZero.val = 0;
			return (0);
		}
	}
	return (1);
}

long long int ft_correctSize(t_flags *flag, long long int number)
{
	if (flag->ll)
		number = (long long int)number;
	else if (flag->l)
		number = (long int)number;
	else
		number = (int)number;
	flag->negative = (number < 0) ? 1 : 0;
	if ( number < 0)
		number = -number;
	return (number);
}

void		ft_setFunction(t_function *function)
{
	function->correctSize = ft_correctSize;
	function->countDigits= ft_countDigits;
	function->printPrefix = ft_printPrefix;
}

void		ft_decimal(va_list args, t_flags flag, unsigned int *nbr_pc)
{
	t_function		function;
	long long int	number;
	unsigned int	digits;
	

	ft_setFunction(&function);
	number = function.correctSize(&flag, va_arg(args,long long int));
	digits = function.countDigits(number, 10);
	if ((int)number == 0)
		digits = ft_analizeZeroCase(&flag);
	ft_calculatePadded(&flag, digits, nbr_pc);
	ft_printAll(flag, number, function);
}
