/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laisarena <marvin@42.fr>                   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 16:27:15 by laisarena         #+#    #+#             */
/*   Updated: 2020/08/19 10:36:52 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_c(va_list args, t_flags flag, unsigned int *nbr_pc)
{
	*nbr_pc += (flag.width.val == 0) ? 1 : flag.width.val; 
	if (flag.justify)
		ft_putchar_fd(va_arg(args, int), 1);
	while (flag.width.val && flag.width.val-- != 1)
		ft_putchar_fd(' ', 1);
	if (!flag.justify)
		ft_putchar_fd(va_arg(args, int), 1);
}
