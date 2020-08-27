/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 12:59:47 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/27 16:05:11 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_setflags(t_flags *flag)
{
	flag->zero = 0;
	flag->justify = 0;
	flag->sign = 0;
	flag->space = 0;
	flag->hasht = 0;
	flag->width.on = 0;
	flag->width.val = 0;
	flag->prec.on = 0;
	flag->prec.val = 0;
}

static char	*ft_precision(char *strflag, t_flags *flag, va_list args)
{
	int		value;

	if (*strflag++ == '.')
		flag->prec.on = 1;
	while (ft_isdigit(*strflag))
		flag->prec.val = flag->prec.val * 10 + *strflag++ - '0';
	if (*strflag == '*')
	{
		if ((value = va_arg(args, int)) < 0)
		{
			flag->prec.on = 0;
			flag->prec.val = 0;
		}
		else
			flag->prec.val = value;
		strflag++;
	}
	return (strflag);
}

static char	*ft_width(char *strflag, t_flags *flag, va_list args)
{
	int		value;

	if (ft_isdigit(*strflag) || *strflag == '*')
		flag->width.on = 1;
	while (ft_isdigit(*strflag))
		flag->width.val = flag->width.val * 10 + *strflag++ - '0';
	if (*strflag == '*')
	{
		if ((value = va_arg(args, int)) < 0)
		{
			flag->justify = 1;
			flag->width.val = -value;
		}
		else
			flag->width.val = value;
		strflag++;
	}
	return (strflag);
}

static char	*ft_checkflags(char *strflag, t_flags *flag)
{
	while (*strflag == '-' || *strflag == '0' || *strflag == '+'
				|| *strflag == ' ' || *strflag == '#')
	{
		if (*strflag == '0')
			flag->zero = 1;
		if (*strflag == '-')
			flag->justify = 1;
		if (*strflag == '+')
			flag->sign = 1;
		if (*strflag == ' ')
			flag->space = 1;
		if (*strflag == '#')
			flag->hasht = 1;
		strflag++;
	}
	return (strflag);
}

/*
** A flag zero é ignorada quando tem precision
**A flag space é ignorada quando tem +
*/

t_flags		ft_treatformatting(char *strflag, va_list args)
{
	t_flags flag;

	ft_setflags(&flag);
	strflag = ft_checkflags(strflag, &flag);
	strflag = ft_width(strflag, &flag, args);
	strflag = ft_precision(strflag, &flag, args);
	if (flag.prec.on)
		flag.zero = 0;
	if (flag.sign)
		flag.space = 0;
	return (flag);
}
