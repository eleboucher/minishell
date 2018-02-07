/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:06:40 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/07 18:19:10 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cmd_launch(char **args)
{
	pid_t pid;

	pid = fork();
	if (!pid)
	{
		if (execve(args[0], args, NULL) == -1)
			ft_printf("error\n");
		return (0);
	}
	else if (pid < 0)
			ft_printf("error\n");
	else
		wait(0);
	return (1);

}
