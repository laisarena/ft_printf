/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:27:15 by lfrasson          #+#    #+#             */
/*   Updated: 2020/09/03 12:07:28 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_character(unsigned int c, t_flags flag, unsigned int *totalprinted)
{
	*totalprinted += (flag.width.val == 0) ? 1 : flag.width.val;
	if (flag.justify)
		ft_putchar_fd(c, 1);
	while (flag.width.val && flag.width.val-- != 1)
		ft_putchar_fd(' ', 1);
	if (!flag.justify)
		ft_putchar_fd(c, 1);
}
