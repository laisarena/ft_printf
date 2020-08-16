/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 14:50:25 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/16 15:35:04 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The Function converts an integer value to a null-terminated string.
** Parameters:
**	n − Value to be converted to a string.
** Return Value:
**	A pointer to the resulting null-terminated string with the converted number.
** Details
**	If value is negative, the resulting string is preceded with a minus
**	sign (-).
*/

static int	ft_countdigits(long l, int len)
{
	int	count;

	count = 1;
	while (l >= len)
	{
		l = l / len;
		count++;
	}
	return (count);
}

static int	ft_validate_base(char *base)
{
	if (!(*base) || !(*(base + 1)))
		return (0);
	while (*base)
	{
		if (*base == '-' || *base == '+')
			return (0);
		if (ft_strchr(base + 1, *base))
			return (0);
		base++;
	}
	return (1);
}

char		*ft_utoa_base(unsigned int n, char *base)
{
	int		digits;
	int		len;
	char	*str;

	if (!ft_validate_base(base))
		return (0);
	len = ft_strlen(base);
	digits = ft_countdigits(n, len);
	if (!(str = malloc((digits + 1) * sizeof(char))))
		return (NULL);
	str[digits] = '\0';
	while (digits > 0)
	{
		str[digits - 1] = base[n % len];
		n = n / len;
		digits--;
	}
	return (str);
}
