/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:22:33 by elebouch          #+#    #+#             */
/*   Updated: 2018/03/09 11:58:19 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		cmd_launch(t_cmd *data, char **args, char **env)
{
	pid_t pid;

	if (!access(data->bin, F_OK))
	{
		pid = fork();
		if (!pid)
		{
			printf("%s", data->bin);
			execve(data->bin, args, env);
		}
		else if (pid < 0)
			ft_printf("error\n");
		else
			wait(0);
	}
	else
		ft_printf("minishell: command not found: %s\n", data->cmd);
	if (data->cmd)
		free(data->cmd);
	if (data->bin)
		free(data->bin);
	if (data->path)
		free(data->path);
	free(data);
	return (1);
}
