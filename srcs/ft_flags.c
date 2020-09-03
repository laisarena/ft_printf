/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 12:59:47 by lfrasson          #+#    #+#             */
/*   Updated: 2020/09/04 09:29:50 by lfrasson         ###   ########.fr       */
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
	flag->negative = 0;
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

static char	*ft_characterflags(char *strflag, t_flags *flag)
{
	while (*strflag == '-' || *strflag == '0' || *strflag == '+' ||
			*strflag == ' ' || *strflag == '#')
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
** If both '0' and '-' flags are specified, the '0' flag is ignored
** If both '+' and 'space' flags are specified, the 'space' flag is ignored.
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
	strflag = ft_characterflags(strflag, &flag);
	strflag = ft_width_precision(strflag, &flag, args);
	strflag = ft_lenthflags(strflag, &flag);
	ft_dealcombinations(&flag);
	return (flag);
}
