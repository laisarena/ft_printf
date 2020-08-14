/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 13:18:03 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/14 13:26:49 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_di(va_list args, t_flags flag)
{
	unsigned int	len;
	char			*str;

	str = ft_itoa(va_arg(args, int));
	len = ft_strlen(str);
	if (flag.precision && flag.precision < len)
	{
		len = flag.precision;
		str = ft_substr(str, 0, len);
	}
	if (flag.justify)
		ft_putstr_fd(str, 1);
	while (flag.width > len && flag.width != 0 && flag.width-- != 1)
		ft_putchar_fd(' ', 1);
	if (!flag.justify)
		ft_putstr_fd(str, 1);
}
