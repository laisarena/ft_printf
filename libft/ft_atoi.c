/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 15:43:58 by lfrasson          #+#    #+#             */
/*   Updated: 2020/09/04 10:35:46 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function that converts the string argument str to an integer (type int)
** Parameters:
**	str − This is the string representation of an integral number.
** Return Value:
** 	This function returns the converted integral number as an int value.
** 	If no valid conversion could be performed, it returns zero.
** Details
**	The function ignores any white-space before the sign or number character
**	The function considers + and - signs
*/

int	ft_atoi(const char *str)
{
	long	nbr;
	int		sign;

	nbr = 0;
	sign = 1;
	while (*str && ft_isspace(*str))
		str++;
	if (*str == '+')
		str++;
	else if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str && ft_isdigit(*str))
		nbr = nbr * 10 + *str++ - '0';
	return ((int)(sign * nbr));
}
