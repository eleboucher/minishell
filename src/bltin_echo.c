/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bltin_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:51:07 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/14 16:32:56 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void print_for_each(char *str)
{
	size_t start;
	size_t end;

	start = (str[0] == '\'' || str[0] == '\"') ? 1 : 0;
	end = ft_strlen(str);
	end = (str[end - 1] == '\'' || str[end - 1] == '\"')? end - 2 : end;
	ft_putnstr(str + start, end);
}

static void print_echo(char **args)
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
			write (1, " ", 1);
		print_for_each(args[i++]);
	}
}

int	bltin_echo(char **args)
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
	print_echo(args + ((fg_n)? 2 : 1));
	if (!fg_n)
		ft_putchar('\n');
	return (1);
}
