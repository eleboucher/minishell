/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bltin_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:51:07 by elebouch          #+#    #+#             */
/*   Updated: 2018/03/09 14:34:09 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_for_each(char *str, char ***env)
{
	size_t	start;
	size_t	end;
	size_t	j;
	int		quote;

	start = (str[0] == '\'' || str[0] == '\"') ? 1 : 0;
	quote = (str[0] == '\'') ? 1 : 0;
	end = (str[ft_strlen(str) - 1] == '\'' || str[ft_strlen(str) - 1] == '\"') ?
		ft_strlen(str) - 1 : ft_strlen(str);
	while (start < end)
	{
		j = start;
		if (str[start] == '$' && !quote)
		{
			start++;
			while (j < end && !ft_isspace(str[j]))
				j++;
			if (env || *env)
				print_fromenv(*env, ft_strsub(str, start, j));
			start = j;
		}
		else
			ft_putchar(str[start]);
		start++;
	}
}

static void	print_echo(char **args, char ***env)
{
	size_t i;
	size_t size;

	i = 0;
	size = 0;
	while (args[size])
		++size;
	i = 0;
	while (i < size)
	{
		if (i)
			write(1, " ", 1);
		print_for_each(args[i++], env);
	}
}

int			bltin_echo(char **args, char ***env)
{
	int fg_n;

	fg_n = 0;
	if (!args[1])
	{
		ft_putchar('\n');
		return (1);
	}
	if (!ft_strncmp(args[1], "-n", 2))
		fg_n = 1;
	print_echo(args + ((fg_n) ? 2 : 1), env);
	if (!fg_n)
		ft_putchar('\n');
	return (1);
}
