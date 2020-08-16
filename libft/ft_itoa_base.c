/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 21:38:44 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/16 15:28:57 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The Function converts an integer value to a null-terminated string.
** Parameters:
**	n − Value to be converted to a string.
**  base - base to convert de integer number
** Return Value:
**	A pointer to the resulting null-terminated string with the converted number.
** Details
**	- If value is negative, the resulting string is preceded with a minus
**	sign (-).
**  - The base is invalid if:
**		base é vazia ou de tamanho 1;
**		base contém duas vezes o mesmo caractere;
**		base contém os caracteres + ou - ou whitespaces;
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
		if (*base == '-' || *base == '+' || ft_isspace(*base))
			return (0);
		if (ft_strchr(base + 1, *base))
			return (0);
		base++;
	}
	return (1);
}

char		*ft_itoa_base(int n, char *base)
{
	long	l;
	int		digits;
	int		sign;
	int		len;
	char	*str;

	if (!ft_validate_base(base))
		return (0);
	len = ft_strlen(base);
	l = n;
	sign = (l < 0) ? 1 : 0;
	l = (l < 0) ? -1 * l : l;
	digits = ft_countdigits(l, len) + sign;
	if (!(str = malloc((digits + 1) * sizeof(char))))
		return (NULL);
	str[digits] = '\0';
	while (digits-- > 0)
	{
		if (digits == 0 && sign)
			str[0] = '-';
		else
			str[digits] = base[l % len];
		l = l / len;
	}
	return (str);
}
