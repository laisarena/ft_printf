/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 10:31:28 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/25 11:01:12 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printstr(t_flags flag, unsigned int neg, char *str, char cnv)
{
	if (!flag.justify)
		while (flag.width.val--)
			if (!flag.zero)
				ft_putchar_fd(' ', 1);
	if (neg)
		ft_putchar_fd('-',1);
	if (flag.sign && !neg  && (cnv == 'd' || cnv == 'i'))
		ft_putchar_fd('+', 1);
	while (flag.prec.val--)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
	if (flag.justify)
		while (flag.width.val--)
			ft_putchar_fd(' ', 1);
}

static void	ft_nbrptrchar(t_flags flag, unsigned int sign, unsigned int len,
							unsigned int *nbr_pc)
{
	if (flag.width.val > flag.prec.val && flag.width.val > len + sign)
		*nbr_pc += flag.width.val;
	else if (flag.prec.val >= flag.width.val && flag.prec.val >= len + sign)
		*nbr_pc += flag.prec.val + sign;
	else
		*nbr_pc += len + sign;
}

/*
** PRECISION - the minimum number of digits to be printed for
**					d, i, o, u, x, and X conversions
**  - When '0' and precision, '0' is ignored.
**  - The sign of the number is not include on precision size
*/

static void	ft_printflag(char *str, t_flags flag, char conversion,
		unsigned int *nbr_pc)
{
	unsigned int	len;
	unsigned int	neg;
	unsigned int	sign;

	neg = (*str == '-') ? 1 : 0;
	sign = (neg || flag.sign) ? 1 : 0;
	str = (*str == '-') ? str + 1 : str;
	len = ft_strlen(str);
	ft_nbrptrchar(flag, sign, len, nbr_pc);
	if (flag.prec.val > len)
		flag.prec.val -= len;
	else
		flag.prec.val = 0;
	if (flag.width.val > len + sign + flag.prec.val)
		flag.width.val += -len - sign - flag.prec.val;
	else
		flag.width.val = 0;
	if (flag.zero && !flag.justify)
		flag.prec.val += flag.width.val;
	ft_printstr(flag, neg, str, conversion);
}

void		ft_integers(va_list args, t_flags flag, unsigned int *nbr_pc,
						char conversion)
{
	char	*str;
	int		value;

	value = va_arg(args, int);
	if (conversion == 'd' || conversion == 'i')
		str = ft_itoa(value);
	if (conversion == 'u')
		str = ft_utoa((unsigned int)value);
	if (conversion == 'x')
		str = ft_utoa_base((unsigned int)value, "0123456789abcdef");
	if (conversion == 'X')
		str = ft_utoa_base((unsigned int)value, "0123456789ABCDEF");
	if (value == 0 && flag.prec.on && !flag.prec.val)
		*str = ' ';
	if (value == 0 && flag.prec.on && !flag.prec.val &&
			(!flag.width.val || flag.sign))
		*str = '\0';
	ft_printflag(str, flag, conversion, nbr_pc);
}
