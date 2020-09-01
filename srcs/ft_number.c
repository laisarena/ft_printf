/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 10:31:28 by laisarena         #+#    #+#             */
/*   Updated: 2020/09/02 10:00:39 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** PRECISION - the minimum number of digits to be printed for
**					d, i, o, u, x, and X conversions
**  - When '0' and precision, '0' is ignored.
**  - The sign of the number is not include on precision size
*/

static unsigned int	ft_calculateprefix(t_flags flag)
{
	if (flag.negative || flag.sign || flag.space)
		return (1);
	if (flag.hash && !flag.zeroexception.on)
		return (2);
	if (flag.conversion == 'p')
		return (2);
	return (0);
}

static void			ft_calculatepadded(t_flags *flag, unsigned int len,
												unsigned int *totalprinted)
{
	unsigned int	prefix;

	prefix = ft_calculateprefix(*flag);
	if (flag->prec.val > len)
		flag->prec.val -= len;
	else
		flag->prec.val = 0;
	if (flag->width.val > len + prefix + flag->prec.val)
		flag->width.val += -len - prefix - flag->prec.val;
	else
		flag->width.val = 0;
	*totalprinted += flag->width.val + flag->prec.val + prefix + len;
	if (flag->zero && !flag->justify)
		flag->prec.val += flag->width.val;
}

static void			ft_printall(t_flags flag,
								long long value,
								t_function function)
{
	if (!flag.justify)
		while (flag.width.val--)
			if (!flag.zero)
				ft_putchar_fd(' ', 1);
	function.printprefix(flag);
	while (flag.prec.val--)
		ft_putchar_fd('0', 1);
	if (!flag.zeroexception.on)
		function.printnumberbase(value, function.base, 1);
	else if (flag.zeroexception.val)
		ft_putchar_fd(flag.zeroexception.val, 1);
	if (flag.justify)
		while (flag.width.val--)
			ft_putchar_fd(' ', 1);
}

long long int		ft_correctsize_signed(t_flags *flag, long long int number)
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
	if (number < 0)
		number = -number;
	return (number);
}

long long int		ft_correctsize_unsigned(t_flags *flag, long long int number)
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

static t_function	ft_setfunctions(t_function *function, t_flags f)
{
	if (f.conversion == 'd' || f.conversion == 'i')
		return (ft_setdecimalfunctions(&ft_correctsize_signed));
	if (f.conversion == 'u')
		return (ft_setdecimalfunctions(&ft_correctsize_unsigned));
	if (f.conversion == 'x' || f.conversion == 'X' || f.conversion == 'p')
		return (ft_sethexadecimalfunctions(f.conversion,
				&ft_correctsize_unsigned));
	return (*function);
}

void				ft_number(va_list args, t_flags flag, unsigned int *nbr_pc)
{
	t_function		function;
	long long int	number;
	unsigned int	digits;

	function = ft_setfunctions(&function, flag);
	number = function.correctsize(&flag, va_arg(args, long long int));
	digits = function.numberdigits(&flag, number, function.sizebase);
	ft_calculatepadded(&flag, digits, nbr_pc);
	ft_printall(flag, number, function);
}
