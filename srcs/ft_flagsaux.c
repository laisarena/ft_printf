/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagsaux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 12:59:47 by lfrasson          #+#    #+#             */
/*   Updated: 2020/09/03 16:50:05 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** PRECISION - the minimum number of digits to be printed for
**					d, i, o, u, x, and X conversions
**  - When '0' and precision, '0' is ignored.
**  - The sign of the number is not include on precision size
*/

static char	*ft_takeformatvalue(char *strflag, unsigned int *value)
{
	while (ft_isdigit(*(strflag)))
		*value = *value * 10 + *strflag++ - '0';
	return (strflag);
}

static char	*ft_takeprecisionarg(char *strflag, t_flags *flag, va_list args)
{
	int		value;

	if ((value = va_arg(args, int)) < 0)
	{
		flag->prec.on = 0;
		flag->prec.val = 0;
	}
	else
		flag->prec.val = value;
	return (strflag);
}

static char	*ft_takewidtharg(char *strflag, t_flags *flag, va_list args)
{
	int		value;

	if ((value = va_arg(args, int)) < 0)
	{
		flag->justify = 1;
		flag->width.val = -value;
	}
	else
		flag->width.val = value;
	return (strflag);
}

char		*ft_width_precision(char *strflag, t_flags *flag, va_list args)
{
	if (ft_isdigit(*strflag) || *strflag == '*')
		flag->width.on = 1;
	strflag = ft_takeformatvalue(strflag, &flag->width.val);
	if (*strflag == '*')
		strflag = ft_takewidtharg(++strflag, flag, args);
	if (*strflag != '.')
		return (strflag);
	flag->prec.on = 1;
	strflag = ft_takeformatvalue(++strflag, &flag->prec.val);
	if (*strflag == '*')
		strflag = ft_takeprecisionarg(++strflag, flag, args);
	return (strflag);
}
