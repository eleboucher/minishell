/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bltin_echo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:51:07 by elebouch          #+#    #+#             */
/*   Updated: 2018/05/03 09:50:45 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_echo(char **args)
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
		ft_printf("%s", args[i++]);
		if (i < size)
			write(1, " ", 1);
	}
}

int			bltin_echo(char **args, char ***env)
{
	int fg_n;

	(void)env;
	fg_n = 0;
	if (!args[1])
	{
		ft_putchar('\n');
		return (1);
	}
	if (!ft_strncmp(args[1], "-n", 2))
		fg_n = 1;
	print_echo(args + ((fg_n) ? 2 : 1));
	if (!fg_n)
		ft_putchar('\n');
	return (1);
}
