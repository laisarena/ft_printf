/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:16:47 by lfrasson          #+#    #+#             */
/*   Updated: 2020/03/03 16:41:05 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_chrbelongset(char const *set, char c)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char const	*ptrs1;
	size_t		start;
	size_t		end;

	if (!s1 || !set)
		return (NULL);
	ptrs1 = s1;
	start = 0;
	while (ft_chrbelongset(set, *ptrs1) && *ptrs1++)
		start++;
	end = ft_strlen(s1);
	if (start == end)
		return (ft_substr(s1, start, 0));
	ptrs1 = &s1[end - 1];
	while (ft_chrbelongset(set, *ptrs1--) && end)
		end--;
	return (ft_substr(s1, start, end - start));
}
