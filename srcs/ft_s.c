/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:51:28 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/14 10:39:58 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_s(va_list args, t_flags flag)
{
	unsigned int	len;
	char		*str;

	len = ft_strlen(str = va_arg(args, char *));
	
	if (flag.precision && flag.precision < len)
		str = ft_substr(str, 0, len = flag.precision);	
	if (flag.justify)
		ft_putstr_fd(str, 1);
	while (flag.width > len && flag.width != 0 && flag.width-- != 1)
		ft_putchar_fd(' ', 1);
	if (!flag.justify)
		ft_putstr_fd(str, 1);
}