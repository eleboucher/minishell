/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 17:33:20 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/14 18:01:06 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_fromenv(char **env, char *var)
{
	int		i;

	i = -1;
	while (env[++i])
		if (!ft_strncmp(env[i], var, ft_strlen(var)))
			break ;
	if (!env[i])
		return (NULL);
	return (ft_strdup(env[i] + (ft_strlen(var) + 1)));
}

void print_fromenv(char **env, char *var)
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
