/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 11:51:56 by lfrasson          #+#    #+#             */
/*   Updated: 2020/02/18 17:37:09 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t len;

	if (!dst)
		return (0);
	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	while (*src && dstsize-- > 1)
		*dst++ = (char)*src++;
	*dst = '\0';
	return (len);
}
