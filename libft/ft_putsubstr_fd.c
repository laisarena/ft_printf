/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsubstr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <lfrasson@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:20:39 by lfrasson          #+#    #+#             */
/*   Updated: 2020/09/03 17:31:22 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putsubstr_fd(const char *s, unsigned int start, size_t len, int fd)
{
	if (!s)
		return ;
	while (s[start] && start < len)
		ft_putchar_fd(s[start++], fd);
}
