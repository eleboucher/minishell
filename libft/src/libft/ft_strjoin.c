/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/31 17:24:58 by elebouch          #+#    #+#             */
/*   Updated: 2018/03/08 18:51:58 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * (ft_strlen(s1)
						+ ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (*s1)
		str[i++] = *(s1++);
	while (*s2)
		str[i++] = *(s2++);
	str[i] = 0;
	return (str);
}

char	*ft_strcleanjoin(char *s1, const char *s2)
{
	char	*tmp;

	if (!(tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(tmp, s1);
	free(s1);
	ft_strcat(tmp, s2);
	return (tmp);
}

char	*ft_strjoinc_clr(char *a, char b)
{
	char	*s;

	if ((s = ft_strmdup(a, 1)) == NULL)
		return (NULL);
	s[ft_strlen(a)] = b;
	free(a);
	return (s);
}

char	*ft_strjoin_clr(char *a, char *b, int d)
{
	char	*s;

	if (!(s = ft_strnew(ft_strlen(a) + ft_strlen(b))))
		return (NULL);
	if (a)
		ft_strcat(s, a);
	if (b)
		ft_strcat(s, b);
	if (d == 2 || d == 0)
		free(a);
	if (d == 2 || d == 1)
		free(b);
	return (s);
}
