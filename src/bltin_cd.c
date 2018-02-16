/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bltin_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:51:46 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/16 12:04:44 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	changedir(char *path, char ***env)
{
	char *pwd;

	pwd = getcwd(NULL, 0);
	if (!chdir(path))
	{
		change_env(env, "OLDPWD", pwd);
		free(pwd);
		pwd = getcwd(NULL, 0);
		change_env(env, "PWD", pwd);
		free(pwd);
	}
	else
	{
		ft_putstr_fd("cd: ", 2);
		if (access(path, F_OK) == -1)
			ft_putstr_fd("no such file or directory: ", 2);
		else if (access(path, R_OK) == -1)
			ft_putstr_fd("permission denied: ", 2);
		else
			ft_putstr_fd("not a directory: ", 2);
		ft_putendl_fd(path, 2);
	}
}

int		bltin_cd(char **args, char ***env)
{
	if (ft_arrsize(args) > 2)
		ft_putendl("cd: too many arguments.");
	if (!args[1])
	{
		if (!get_fromenv(*env, "HOME"))
			ft_putendl_fd("cd: HOME not set.", 2);
		else
			changedir(get_fromenv(*env, "HOME") + 5, env);
	}
	else if (!ft_strcmp(args[1], "-"))
	{
		if (!get_fromenv(*env, "OLDPWD"))
			ft_putendl_fd("cd: OLDPWD not set.", 2);
		else
			changedir(get_fromenv(*env, "OLDPWD") + 7, env);
	}
	else
		changedir(args[1], env);
	return (1);
}
