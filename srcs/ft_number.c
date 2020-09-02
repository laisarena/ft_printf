/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 10:31:28 by laisarena         #+#    #+#             */
/*   Updated: 2020/09/02 15:24:16 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** PRECISION - the minimum number of digits to be printed for
**					d, i, o, u, x, and X conversions
**  - When '0' and precision, '0' is ignored.
**  - The sign of the number is not include on precision size
*/

static long long int	ft_correctsize_signed(t_flags *flag,
												long long int number)
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

static long long int	ft_correctsize_unsigned(t_flags *flag,
												long long int number)
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

static t_function		ft_setfunctions(t_function *function, t_flags f)
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

void					ft_number(va_list args, t_flags flag,
									unsigned int *totalprinted)
{
	t_function		function;
	long long int	number;
	unsigned int	digits;

	function = ft_setfunctions(&function, flag);
	number = function.correctsize(&flag, va_arg(args, long long int));
	digits = function.numberdigits(&flag, number, function.sizebase);
	ft_calculatepadded(&flag, digits, totalprinted);
	ft_printall(flag, number, function);
}
