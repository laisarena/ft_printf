/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:27:38 by lfrasson          #+#    #+#             */
/*   Updated: 2020/03/03 15:24:05 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *ptrdst;
	unsigned char *ptrsrc;

	if (!dst && !src)
		return (NULL);
	ptrdst = (unsigned char *)dst;
	ptrsrc = (unsigned char *)src;
	if (src >= dst)
		ft_memcpy(dst, src, len);
	else
	{
		while (len--)
			ptrdst[len] = ptrsrc[len];
	}
	return (dst);
}
