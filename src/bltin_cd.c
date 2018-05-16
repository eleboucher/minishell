/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bltin_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:51:46 by elebouch          #+#    #+#             */
/*   Updated: 2018/05/16 14:40:38 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	changedir(char *path, char ***env)
{
	char *pth;

	if (!(pth = get_cd_path(path, get_fromenv(*env, "PWD"))))
		exit(EXIT_FAILURE);
	if (!chdir(pth))
	{
		change_env(env, "OLDPWD", get_fromenv(*env, "PWD"));
		change_env(env, "PWD", pth);
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
		ft_putendl_fd(pth, 2);
	}
	free(pth);
}

int		bltin_cd(char **args, char ***env)
{
	if (!env)
		return (0);
	if (ft_arrsize(args) > 2)
		ft_putendl("cd: too many arguments.");
	if (!args[1])
	{
		if (!get_fromenv(*env, "HOME"))
			ft_putendl_fd("cd: HOME not set.", 2);
		else
			changedir(get_fromenv(*env, "HOME"), env);
	}
	else if (!ft_strcmp(args[1], "-"))
	{
		if (!get_fromenv(*env, "OLDPWD"))
			ft_putendl_fd("cd: OLDPWD not set.", 2);
		else
		{
			changedir(get_fromenv(*env, "OLDPWD"), env);
			ft_printf("%s\n", get_fromenv(*env, "PWD"));
		}
	}
	else
		changedir(args[1], env);
	return (1);
}
