/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 14:38:16 by lfrasson          #+#    #+#             */
/*   Updated: 2020/02/18 17:08:08 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The function places zeros in the first n bytes of the string s*/

void	ft_bzero(void *s, size_t n)
{
	char *ptr;

	ptr = s;
	while (n--)
		*ptr++ = 0;
}
