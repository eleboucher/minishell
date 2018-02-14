/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bltin_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:56:36 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/14 17:24:05 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int bltin_env(char **args, char ***env)
{
	char **envi;

	(void)args;
	envi = *env;
	while (*envi)
	{
		ft_putendl(*envi);
		envi++;
	}
	return (1);
}
