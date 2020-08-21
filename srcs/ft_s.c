/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:51:28 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/20 20:34:00 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Function to print strings
** PRECISION - the maximum number of characters to be printed from a string
** WIDTH - If the value to be printed is shorter than the field width,
** it is padded with spaces
*/

static char	*ft_strnull(void)
{
	char *str;

	if (!(str = ft_calloc(7, sizeof(char))))
		return (NULL);
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = '\0';
	return (str);
}

void		ft_s(const char *str, t_flags flag, unsigned int *nbr_pc)
{
	unsigned int	len;

	if (!str)
		str = ft_strnull();
	if (str)
	{
		len = ft_strlen(str);
		if (flag.prec.on && flag.prec.val < len)
		{
			len = flag.prec.val;
			str = ft_substr(str, 0, len);
		}
		if (flag.justify)
			ft_putstr_fd((char *)str, 1);
		*nbr_pc += (flag.width.val > len) ? flag.width.val : len;
		while (flag.width.val > len && flag.width.val--)
		{
			if (!flag.justify && flag.zero)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
		}
		if (!flag.justify)
			ft_putstr_fd((char *)str, 1);
	}
}
