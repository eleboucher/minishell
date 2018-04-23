/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bltin_unsetenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:56:46 by elebouch          #+#    #+#             */
/*   Updated: 2018/03/09 14:32:21 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**rmfromenv(char **env, int index)
{
	char	**new;
	int		i;
	int		j;

	if (!(new = (char **)malloc(sizeof(char*) * (ft_arrsize(env)))))
		exit(EXIT_FAILURE);
	i = 0;
	j = 0;
	new[ft_arrsize(env) - 1] = 0;
	while (i < (int)ft_arrsize(env))
	{
		if (i != index)
		{
			if (!(new[j] = ft_strdup(env[i])))
				exit(EXIT_FAILURE);
			j++;
		}
		free(env[i]);
		i++;
	}
	free(env);
	return (new);
}

int		bltin_unsetenv(char **args, char ***env)
{
	int argscount;

	argscount = 0;
	if (!env || !*env)
		return (1);
	if (ft_arrsize(args) < 2)
	{
		ft_putendl_fd("unsetenv: Too few arguments.", 2);
		return (1);
	}
	while (args[++argscount])
	{
		if (get_fromenv(*env, args[argscount]))
			*env = rmfromenv(*env, get_index_fromenv(*env, args[argscount]));
		else
		{
			ft_putstr_fd("unsetenv: ", 2);
			ft_putstr_fd(args[argscount], 2);
			ft_putendl_fd(" unknown.", 2);
		}
	}
	return (1);
}
