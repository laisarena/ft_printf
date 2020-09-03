/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_auxnumberfunctions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/02 14:57:39 by lfrasson          #+#    #+#             */
/*   Updated: 2020/09/03 17:04:04 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void				ft_printnumberbase_fd(long long number,
											char *digitsbase, int fd)
{
	unsigned int base;

	base = ft_strlen(digitsbase);
	if (number >= base)
		ft_printnumberbase_fd(number / base, digitsbase, fd);
	ft_putchar_fd(digitsbase[number % base], fd);
}

static unsigned int	ft_countdigits(long long int number, unsigned int sizebase)
{
	unsigned int	digits;

	digits = 1;
	while (number >= sizebase && digits++)
		number = number / sizebase;
	return (digits);
}

static unsigned int	ft_analizezerocase(t_flags *flag)
{
	flag->zeroexception.on = 1;
	if (flag->prec.on && !flag->prec.val)
	{
		if (flag->width.val && !flag->sign && flag->conversion != 'p')
			flag->zeroexception.val = ' ';
		else
		{
			flag->zeroexception.val = 0;
			return (0);
		}
	}
	return (1);
}

unsigned int		ft_numberdigits(t_flags *flag, long long int number,
										unsigned int sizebase)
{
	if ((int)number == 0)
		return (ft_analizezerocase(flag));
	return (ft_countdigits(number, sizebase));
}
