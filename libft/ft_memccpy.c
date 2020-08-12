/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 13:07:48 by lfrasson          #+#    #+#             */
/*   Updated: 2020/02/07 17:56:19 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*ptrdst;
	unsigned char	*ptrsrc;

	ptrdst = (unsigned char *)dst;
	ptrsrc = (unsigned char *)src;
	while (*ptrsrc != (unsigned char)c && n--)
		*ptrdst++ = *ptrsrc++;
	if (*ptrsrc != (unsigned char)c)
		return (NULL);
	*ptrdst++ = *ptrsrc++;
	return (ptrdst);
}
