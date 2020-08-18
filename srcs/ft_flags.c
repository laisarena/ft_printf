/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 12:59:47 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/18 14:12:08 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_setflags(t_flags *flag)
{
	flag->zero = 0;
	flag->justify = 0;
	flag->width = 0;
	flag->precision = 0;
	flag->zprecision = 0;
}

static char	*ft_valueflag(char *strflag, unsigned int *flag, int value)
{
	*flag = (value < 0) ? 0 : value;
	return (++strflag);
}

static char	*ft_width(char *strflag, unsigned int *flag)
{
	while (ft_isdigit(*strflag))
		*flag = *flag * 10 + *strflag++ - '0';
	return (strflag);
}

static char	*ft_precision(char *strflag, t_flags *flag)
{
	while (ft_isdigit(*strflag))
		flag->precision = flag->precision * 10 + *strflag++ - '0';
	if (flag->precision == 0)
		flag->zprecision = 1;
	return (strflag);
}

t_flags		ft_checkflag(char *strflag, va_list args)
{
	int		value;
	t_flags flag;

	ft_setflags(&flag);
	if (*strflag == '0')
		strflag = ft_valueflag(strflag, &flag.zero, 1);
	if (*strflag == '-')
		strflag = ft_valueflag(strflag, &flag.justify, 1);
	if (*strflag == '*')
	{	
		value =  va_arg(args, int);
		if (value < 0)
		{
			flag.justify = 1;
			strflag = ft_valueflag(strflag, &flag.width, value * -1);
		}
		else
			strflag = ft_valueflag(strflag, &flag.width, value);
	}
	strflag = ft_width(strflag, &flag.width);
	if (*strflag == '.')
	{
		if (*(strflag + 1) == '*')
			strflag = ft_valueflag(strflag++, &flag.precision, va_arg(args, int));
		else if (ft_isdigit(*(strflag + 1)))
			strflag = ft_precision(++strflag, &flag);
		else
			flag.zprecision = 1;
	}
	return (flag);
}
