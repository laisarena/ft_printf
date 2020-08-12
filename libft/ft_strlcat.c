/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 12:21:44 by lfrasson          #+#    #+#             */
/*   Updated: 2020/01/29 17:31:05 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		dstlen;
	size_t		ret;

	dstlen = ft_strlen(dst);
	ret = dstlen + ft_strlen(src);
	if (dstsize == 0 || dstlen >= dstsize)
		return (dstsize + ft_strlen(src));
	dst = dst + dstlen;
	dstsize = dstsize - dstlen;
	while (*src && dstsize-- > 1)
		*dst++ = *src++;
	*dst = '\0';
	return (ret);
}
