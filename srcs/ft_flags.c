/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 12:59:47 by laisarena         #+#    #+#             */
/*   Updated: 2020/09/01 11:04:26 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_setflags(t_flags *flag)
{
	flag->zero = 0;
	flag->justify = 0;
	flag->sign = 0;
	flag->space = 0;
	flag->hash = 0;
	flag->l = 0;
	flag->ll = 0;
	flag->h = 0;
	flag->hh = 0;
	flag->width.on = 0;
	flag->width.val = 0;
	flag->prec.on = 0;
	flag->prec.val = 0;
	flag->zeroexception.on = 0;
	flag->zeroexception.val = '0';
}

static char	*ft_lenthflags(char *strflag, t_flags *flag)
{
	if (*strflag)
	{
		if (*strflag == 'l' && *(strflag + 1) == 'l')
			flag->ll = 1;
		else if (*strflag == 'l')
			flag->l = 1;
		if (*strflag == 'h' && *(strflag + 1) == 'h')
			flag->hh = 1;
		else if (*strflag == 'h')
			flag->h = 1;
	}
	return (++strflag);
}

static char	*ft_precision(char *strflag, t_flags *flag, va_list args)
{
	int		value;

	if (*strflag == '.')
	{
		flag->prec.on = 1;
		while (ft_isdigit(*(++strflag)))
			flag->prec.val = flag->prec.val * 10 + *strflag - '0';
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

static char	*ft_characterheckflags(char *strflag, t_flags *flag)
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
			flag->hash = 1;
		strflag++;
	}
	return (strflag);
}

/*
** A flag zero é ignorada quando tem precision
** A flag space é ignorada quando tem +
*/

static void	ft_dealcombinations(t_flags *flag)
{
	if (flag->prec.on)
		flag->zero = 0;
	if (flag->sign)
		flag->space = 0;
}

t_flags		ft_treatformatting(char *strflag, va_list args)
{
	t_flags flag;

	ft_setflags(&flag);
	strflag = ft_characterheckflags(strflag, &flag);
	strflag = ft_width(strflag, &flag, args);
	strflag = ft_precision(strflag, &flag, args);
	strflag = ft_lenthflags(strflag, &flag);
	ft_dealcombinations(&flag);
	return (flag);
}
