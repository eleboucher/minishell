/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:04:58 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/07 18:39:38 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	execute(char **args)
{
	static char	*bltin_str[] = {"echo", "cd", "env", "setenv",
		"unsetenv", "exit"};
	static int	(*bltin_func[]) (char **) = { &bltin_echo, &bltin_cd,
		&bltin_exit, &bltin_setenv, &bltin_unsetenv, bltin_env};
	int 		i;

	i = -1;
	if (!args[0])
		return (1);
	while(++i < 6)
	{
		if (!ft_strcmp(args[0], bltin_str[i])) 
			return (bltin_func[i](args));
	}
	return (cmd_launch(args));
}
