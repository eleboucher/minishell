/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bltin_cd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:51:46 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/14 17:18:55 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int bltin_cd(char **args, char ***env)
{
	(void)env;
	if (!args[1])
		return (1);
	if (chdir(args[1]) != 0)
		ft_printf("error\n");
		return (1);
}
