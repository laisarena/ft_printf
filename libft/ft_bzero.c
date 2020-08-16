/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:38:16 by lfrasson          #+#    #+#             */
/*   Updated: 2020/08/16 15:32:40 by laisarena        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function places zeros in the first n bytes of the string s.
*/

void	ft_bzero(void *s, size_t n)
{
	char *ptr;

	ptr = s;
	while (n--)
		*ptr++ = 0;
}
