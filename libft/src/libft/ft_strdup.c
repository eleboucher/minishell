/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 11:31:15 by elebouch          #+#    #+#             */
/*   Updated: 2018/03/08 18:52:20 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *dest;
	char *cpy;

	if (!(dest = (char*)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	cpy = dest;
	while (*s1)
		*(dest++) = *(s1++);
	*dest = '\0';
	return (cpy);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*snew;

	if (!(snew = (char *)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	snew[n] = '\0';
	return (ft_strncpy(snew, s, n));
}

char	*ft_strmdup(const char *a, size_t n)
{
	return (ft_strndup(a, ft_strlen(a) + n));
}
