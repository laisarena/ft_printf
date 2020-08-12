/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfrasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:18:24 by lfrasson          #+#    #+#             */
/*   Updated: 2020/03/04 14:57:34 by lfrasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_substrnbr(char const *s, char c)
{
	int		count;

	if (*s == c || !(*s))
		count = 0;
	else
		count = 1;
	while (*s)
	{
		if (*s == c && !(*(s + 1) == c || *(s + 1) == '\0'))
			count++;
		s++;
	}
	return (count);
}

static char	**ft_fillarray(char const *s, char c, char **strarray, int n)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	while (i < n && n != 0)
	{
		if (!(temp = ft_strchr(s, c)))
			temp = ft_strchr(s, '\0');
		len = temp - s;
		if (len > 0)
		{
			if (!(strarray[i] = malloc(sizeof(char) * (len + 1))))
				return (NULL);
			ft_strlcpy(strarray[i], s, len + 1);
			i++;
		}
		if (i != n)
			s = (char const*)temp + 1;
	}
	strarray[i] = NULL;
	return (strarray);
}

char		**ft_split(char const *s, char c)
{
	char	**strarray;
	int		n;

	if (!s)
		return (NULL);
	n = ft_substrnbr(s, c);
	if (!(strarray = malloc(sizeof(char *) * (n + 1))))
		return (NULL);
	return (ft_fillarray(s, c, strarray, n));
}
