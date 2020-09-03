/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:51:28 by lfrasson          #+#    #+#             */
/*   Updated: 2020/09/03 17:30:35 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Function to print strings
** PRECISION - the maximum number of characters to be printed from a string
** WIDTH - If the value to be printed is shorter than the field width,
** it is padded with spaces
*/

static char		*ft_strnull(void)
{
	char *str;

	if (!(str = ft_calloc(7, sizeof(char))))
		return (NULL);
	str[0] = '(';
	str[1] = 'n';
	str[2] = 'u';
	str[3] = 'l';
	str[4] = 'l';
	str[5] = ')';
	str[6] = '\0';
	return (str);
}

static void		ft_printwidth(t_flags flag)
{
	if (!flag.justify && flag.zero)
		ft_putchar_fd('0', 1);
	else
		ft_putchar_fd(' ', 1);
}

static void		ft_printstring(t_flags flag, const char *str, unsigned int len)
{
	if (flag.justify)
		ft_putsubstr_fd(str, 0, len, 1);
	while (flag.width.val--)
		ft_printwidth(flag);
	if (!flag.justify)
		ft_putsubstr_fd(str, 0, len, 1);
}

static void		ft_calculatestringpadded(t_flags *flag, unsigned int *len,
										unsigned int *totalprinted)
{
	if (flag->prec.on && flag->prec.val < *len)
		*len = flag->prec.val;
	if (flag->width.val > *len)
		flag->width.val -= *len;
	else
		flag->width.val = 0;
	*totalprinted += flag->width.val + *len;
}

void			ft_string(const char *str, t_flags flag,
							unsigned int *totalprinted)
{
	unsigned int	len;

	if (!str)
		str = ft_strnull();
	len = ft_strlen(str);
	ft_calculatestringpadded(&flag, &len, totalprinted);
	ft_printstring(flag, str, len);
}
