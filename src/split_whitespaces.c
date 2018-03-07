/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_whitespaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:46:48 by elebouch          #+#    #+#             */
/*   Updated: 2018/03/07 18:14:05 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_countsplit(const char *str)
{
	size_t	count;
	int		inword;

	inword = 0;
	count = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (inword && (*str == ' ' || *str == '\t'))
			inword = 0;
		if (!inword && *str != ' ' && *str != '\t')
		{
			count++;
			inword = 1;
		}
		str++;
	}
	return (count);
}

char			**split_whitespaces(char const *s)
{
	size_t	count;
	size_t	l;
	size_t	k;
	char	**array;

	count = ft_countsplit(s);
	if (!(array = (char **)malloc((count + 1) * sizeof(char *))))
		return (NULL);
	l = 0;
	while (count--)
	{
		k = 0;
		while ((*s == ' ' || *s == '\t') && *s)
			s++;
		while (*s != ' ' && *s != '\t' && *s)
		{
			k++;
			s++;
		}
		if (!(array[l] = ft_strsub((const char *)(s - k), 0, k)))
			return (NULL);
		l++;
	}
	array[l] = 0;
	return (array);
}
