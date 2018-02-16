/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:33:20 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/16 11:39:41 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **realloc_env(char **env, int size)
{
	char **new;
	int	i;

	if (!(new = (char **)malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	i = -1;
	new[size] = 0;
	while (env[++i] && i < size)
	{
		new[i] = ft_strdup(env[i]);
		free(env[i]);
	}
	free(env);
	return(new);
}

int 	get_index_fromenv(char **env, char *var)
{
	int		i;

	i = -1;
	while (env[++i])
		if (!ft_strncmp(env[i], var, ft_strlen(var)))
			break ;
	return (i);
}

char *get_fromenv(char **env, char *var)
{
	int		i;

	i = -1;
	while (env[++i])
		if (!ft_strncmp(env[i], var, ft_strlen(var)))
			break ;
	return (env[i]);
}

void	print_fromenv(char **env, char *var)
{
	int		i;

	i = -1;
	while (env[++i])
		if (!ft_strncmp(env[i], var, ft_strlen(var)))
			break ;
	if (!env[i])
		return ;
	ft_putstr(env[i] + (ft_strlen(var) + 1));
	free(var);
}
