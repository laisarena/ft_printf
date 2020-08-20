/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 16:16:41 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/20 16:47:22 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printstr(t_flags flag, char *str)
{
	if (!flag.justify)
		while (flag.width.val--)
			if (!flag.zero)
				ft_putchar_fd(' ', 1);
	ft_putstr_fd("0x", 1);
	while (flag.prec.val--)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
	if (flag.justify)
		while (flag.width.val--)
			ft_putchar_fd(' ', 1);
}

static void	ft_nbrptrchar(t_flags flag, unsigned int len, unsigned int *nbr_pc)
{
	if (flag.width.val > flag.prec.val && flag.width.val > len + 2)
		*nbr_pc += flag.width.val;
	else if (flag.prec.val >= flag.width.val && flag.prec.val >= len)
		*nbr_pc += flag.prec.val + 2;
	else
		*nbr_pc += len + 2;
}

static void	ft_printflag(char *str, t_flags flag, unsigned int *nbr_pc)
{
	unsigned int	len;

	len = ft_strlen(str);
	ft_nbrptrchar(flag, len, nbr_pc);
	if (flag.prec.val > len)
		flag.prec.val += - len;
	else
		flag.prec.val = 0;
	if (flag.width.val > len + 2 + flag.prec.val)
		flag.width.val += - len - 2 - flag.prec.val;
	else
		flag.width.val = 0;
	if (flag.zero && !flag.justify)
		flag.prec.val = flag.prec.val + flag.width.val;
	ft_printstr(flag, str);
}

void		ft_p(va_list args, t_flags flag, unsigned int *nbr_pc)
{
	char			*str;
	unsigned long	value;

	value = va_arg(args, unsigned long);
	str = ft_ultoa_base(value, "0123456789abcdef");
	if (value == 0 && flag.prec.on && !flag.prec.val)
		*str = '\0';
	//	*str = ' ';
	//if (value == 0 && flag.prec.on && !flag.prec.val && !flag.width.val)
	//	*str = '\0';
	ft_printflag(str, flag, nbr_pc);
}
