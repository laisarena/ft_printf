/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:50:43 by laisarena         #+#    #+#             */
/*   Updated: 2020/09/02 14:55:25 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printprefix_hexadecimal(t_flags flag)
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

t_function	ft_sethexadecimalfunctions(char conversion,
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
