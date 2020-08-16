/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 13:18:03 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/15 18:03:03 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_printdi(unsigned int precision, unsigned int sign, char *str)
{
	if (sign)
		ft_putchar_fd('-', 1);
	while (precision--)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
}

void		ft_di(va_list args, t_flags flag)
{
	unsigned int	len;
	unsigned int	sign;
	char			*str;

	str = ft_itoa(va_arg(args, int));
	len = ft_strlen(str);
	sign = (*str == '-') ? 1 : 0;
	str = ft_substr(str, sign, len - sign);
	if (flag.precision > len - sign)
		flag.precision = flag.precision - len + sign;
	else
		flag.precision = 0;
	if (flag.justify)
		ft_printdi(flag.precision, sign, str);
	while (flag.width > len + flag.precision
			&& flag.width != 0 && flag.width-- != 1)
	{
		if (flag.zero && !flag.justify)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
	}
	if (!flag.justify)
		ft_printdi(flag.precision, sign, str);
}
