/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 10:31:28 by lfrasson          #+#    #+#             */
/*   Updated: 2020/09/03 16:49:59 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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
		return (ft_sethexafunctions(f.conversion, &ft_correctsize_unsigned));
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
