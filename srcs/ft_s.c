/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:51:28 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/17 16:29:57 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
 * Function to print strings
 * PRECISION - the maximum number of characters to be printed from a string
 * WIDTH - If the value to be printed is shorter than the field width,
 * it is padded with spaces 
 */

void	ft_s(va_list args, t_flags flag, unsigned int *nbr_pc)
{
	unsigned int	len;
	char			*str;

	str = va_arg(args, char *);
	len = ft_strlen(str);
	if (flag.precision && flag.precision < len)
	{
		len = flag.precision;
		str = ft_substr(str, 0, len);
	}
	if (flag.justify)
		ft_putstr_fd(str, 1);
	*nbr_pc += (flag.width > len) ? flag.width : len;
	while (flag.width > len && flag.width != 0 && flag.width-- != 1)
		ft_putchar_fd(' ', 1);
	if (!flag.justify)
		ft_putstr_fd(str, 1);
}
