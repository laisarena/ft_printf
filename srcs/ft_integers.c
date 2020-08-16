/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 10:31:28 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/16 17:11:59 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printstr(unsigned int pr, unsigned int sign, char *str, char cnv)
{
	if (sign)
		ft_putchar_fd('-', 1);
	if (cnv == 'p')
		ft_putstr_fd("0x", 1);
	while (pr--)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
}

static void	ft_printflag(char *str, t_flags flag, char conversion)
{
	unsigned int	len;
	unsigned int	sign;

	len = ft_strlen(str);
	if (conversion == 'p')
		len = len + 2;
	sign = (*str == '-') ? 1 : 0;
	str = (*str == '-') ? str + 1 : str;
	if (flag.precision > len - sign)
		flag.precision = flag.precision - len + sign;
	else
		flag.precision = 0;
	if (flag.justify)
		ft_printstr(flag.precision, sign, str, conversion);
	while (flag.width > len + flag.precision
			&& flag.width != 0 && flag.width-- != 1)
	{
		if (flag.zero && !flag.justify)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
	}
	if (!flag.justify)
		ft_printstr(flag.precision, sign, str, conversion);
}

void		ft_integers(va_list args, t_flags flag, char conversion)
{
	char			*str;

	if (conversion == 'd' || conversion == 'i')
		str = ft_itoa(va_arg(args, int));
	if (conversion == 'u')
		str = ft_utoa(va_arg(args, unsigned int));
	if (conversion == 'x')
		str = ft_utoa_base(va_arg(args, unsigned int), "0123456789abcdef");
	if (conversion == 'X')
		str = ft_utoa_base(va_arg(args, unsigned int), "0123456789ABCDEF");
	if (conversion == 'p')
		str = ft_ultoa_base(va_arg(args, unsigned long), "0123456789abcdef");
	ft_printflag(str, flag, conversion);
}
