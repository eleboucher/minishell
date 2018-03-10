/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bltin_setenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:56:42 by elebouch          #+#    #+#             */
/*   Updated: 2018/03/10 10:29:16 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	change_env(char ***env, char *var, char *value)
{
	int		index;
	char	*tmp;
	char	**envi;

	index = get_index_fromenv(*env, var);
	tmp = ft_strjoin("=", value);
	envi = *env;
	if (envi[index])
	{
		free(envi[index]);
		if (value)
			envi[index] = ft_strjoin(var, tmp);
		else
			envi[index] = ft_strjoin(var, "=");
	}
	else
	{
		envi = realloc_env(envi, index + 1);
		if (value)
			envi[index] = ft_strjoin(var, tmp);
		else
			envi[index] = ft_strjoin(var, "=");
	}
	*env = envi;
	free(tmp);
}

int		bltin_setenv(char **args, char ***env)
{
	if (!args[1])
	{
		bltin_env(args, env);
		return (1);
	}
	if (args[2])
	{
		if (args[3])
		{
			ft_putendl_fd("setenv: Too many arguments.", 2);
			return (1);
		}
		change_env(env, args[1], args[2]);
	}
	return (1);
}
