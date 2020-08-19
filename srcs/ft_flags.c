/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 12:59:47 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/19 13:11:42 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_setflags(t_flags *flag)
{
	flag->zero = 0;
	flag->justify = 0;
	flag->width.on = 0;
	flag->width.val = 0;
	flag->prec.on = 0;
	flag->prec.val = 0;
}

static char	*ft_turnonflag(char *strflag, unsigned int *flag)
{
	*flag = 1;
	return (++strflag);
}

static char	*ft_valueflag(char *strflag, t_flag_val *flag, int value)
{
	if (value < 0)
	{
		flag->on = 0;
		flag->val = 0;
	}
	else
	{
		flag->on = 1 ;
		flag->val =  value;
	}
	return (++strflag);
}

static char	*ft_width_precision(char *strflag, t_flag_val *flag)
{
	while (ft_isdigit(*strflag))
	{	
		flag->on = 1;
		flag->val = flag->val * 10 + *strflag++ - '0';
	}
	return (strflag);
}

t_flags		ft_checkflag(char *strflag, va_list args)
{
	int		value;
	t_flags flag;

	ft_setflags(&flag);
	if (*strflag == '0')
		strflag = ft_turnonflag(strflag, &flag.zero);
	if (*strflag == '-')
		strflag = ft_turnonflag(strflag, &flag.justify);
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
	strflag = ft_width_precision(strflag, &flag.width);
	if (*strflag == '.')
	{
		if (*(strflag + 1) == '*')
			strflag = ft_valueflag(strflag++, &flag.prec, va_arg(args, int));
		else if (ft_isdigit(*(strflag + 1)))
			strflag = ft_width_precision(++strflag, &flag.prec);
		else
			flag.prec.on = 1;
	}
	return (flag);
}
