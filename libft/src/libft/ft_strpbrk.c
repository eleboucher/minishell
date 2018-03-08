/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 18:37:30 by elebouch          #+#    #+#             */
/*   Updated: 2018/03/08 18:37:44 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strpbrk(const char *s, const char *charset)
{
	if (!s || !charset)
		return (NULL);
	while (*s)
	{
		if (ft_strchr(charset, *s))
			return ((char *)s);
		++s;
	}
	return (NULL);
}

int		ft_strpbrk_pos(const char *s, const char *charset)
{
	int	i;

	if (!s || !charset)
		return (-1);
	i = 0;
	while (s[i])
	{
		if (ft_strchr(charset, s[i]))
			return (i);
		++i;
	}
	return (-1);
}
