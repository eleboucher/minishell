/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:04:58 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/15 12:17:57 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_bin(char *cmd, char *paths)
{
	char **split;
	char *tmp;
	struct stat stats;
	int i;
	int status;

	i = -1;
	if (!paths)
		return (NULL);
	if (!(split = ft_strsplit(paths, ':')))
		return (NULL);
	while (split[++i])
	{
		tmp = (split[i][ft_strlen(split[i]) - 1] == '/') ? ft_strdup(split[i]):
			ft_strjoin(split[i], "/");
		tmp = ft_strcleanjoin(tmp, cmd);
		if (!(status = stat(tmp, &stats)))
			break;
		else
			free(tmp);
	}
	return ((status == -1) ? cmd : tmp);
}

t_cmd	*get_path(char **env, char *cmd)
{
	int		i;
	t_cmd	*data;

	i = -1;
	if (!(data = (t_cmd*)malloc(sizeof(t_cmd))))
		return (0);
	while (env[++i])
		if (!ft_strncmp(env[i], "PATH=", 5))
			break ;
	if (env[i])
		data->path = ft_strsub(env[i], 6, ft_strlen(env[i]));
	else
		data->path = NULL;
	data->bin = get_bin(cmd, data->path);
	data->cmd = ft_strdup(cmd);
	return (data);
}

int	execute(char **args, char ***env)
{
	static char	*bltin_str[] = {"echo", "cd", "env", "setenv",
		"unsetenv", "exit"};
	static int	(*bltin_func[]) (char **, char ***) = { &bltin_echo, &bltin_cd,
		&bltin_env, &bltin_setenv, &bltin_unsetenv, &bltin_exit};
	int 		i;
	t_cmd		*data;

	i = -1;
	if (!args[0])
		return (1);
	while(++i < 6)
		if (!ft_strcmp(args[0], bltin_str[i]))
			return (bltin_func[i](args, env));
	data = get_path(*env, args[0]);
	return (cmd_launch(data, args, *env));
}
