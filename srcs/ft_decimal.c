/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/28 13:50:53 by lfrasson          #+#    #+#             */
/*   Updated: 2020/09/03 17:17:29 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printprefix_decimal(t_flags flag)
{
	if (flag.negative)
		ft_putchar_fd('-', 1);
	else if (flag.sign)
		ft_putchar_fd('+', 1);
	else if (flag.space)
		ft_putchar_fd(' ', 1);
}

t_function	ft_setdecimalfunctions(long long int (*correctsize)())
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
