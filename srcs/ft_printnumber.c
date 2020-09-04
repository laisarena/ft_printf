/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 16:16:41 by lfrasson          #+#    #+#             */
/*   Updated: 2020/09/04 09:41:17 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

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

void				ft_calculatepadded(t_flags *flag, unsigned int len,
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

void				ft_printall(t_flags flag, long long value,
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
