/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:22:33 by elebouch          #+#    #+#             */
/*   Updated: 2018/03/12 17:37:19 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_data(t_cmd **to_free)
{
	t_cmd *data;

	data = *to_free;
	if (data->cmd)
		free(data->cmd);
	if (data->bin)
		free(data->bin);
	if (data->path)
		free(data->path);
	free(data);
}

int			cmd_launch(t_cmd *data, char **args, char **env)
{
	pid_t pid;

	if (!access(data->bin, F_OK))
	{
		pid = fork();
		if (!pid)
		{
			if (execve(data->bin, args, env) == -1)
				ft_printf("minishell: command not found: %s\n", data->cmd);
			exit(0);
		}
		else if (pid < 0)
			ft_printf("error\n");
		else
			wait(0);
	}
	else
		ft_printf("minishell: command not found: %s\n", data->cmd);
	free_data(&data);
	return (1);
}
