/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:27:07 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/07 18:44:30 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	bltin_echo(char **args)
{
	if (!args[1])
		return (0);
	ft_printf("%s",args[1]);
	return (1);
}

int bltin_cd(char **args)
{
	if (!args[1])
		return (0);
	if (chdir(args[1]) != 0)
		ft_printf("error\n");
	return (1);
}

int bltin_exit(char **args)
{
	(void)args;
	return (0);
}
