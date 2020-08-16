/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 14:41:00 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/16 15:31:26 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The Function converts an unsigned integer value to a null-terminated string.
** Parameters:
**	n − Value to be converted to a string.
** Return Value:
**	A pointer to the resulting null-terminated string with the converted number
*/

static int	ft_countdigits(unsigned int l)
{
	int	count;

	count = 1;
	while (l >= 10)
	{
		l = l / 10;
		count++;
	}
	return (count);
}

char		*ft_utoa(unsigned int n)
{
	int		digits;
	char	*str;

	digits = ft_countdigits(n);
	if (!(str = malloc((digits + 1) * sizeof(char))))
		return (NULL);
	str[digits] = '\0';
	while (digits > 0)
	{
		str[digits - 1] = n % 10 + '0';
		n = n / 10;
		digits--;
	}
	return (str);
}
