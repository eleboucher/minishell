/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:46:48 by elebouch          #+#    #+#             */
/*   Updated: 2018/03/09 13:23:32 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getargs(char *cmd, t_args *args)
{
	char	*str;
	int		pos;

	if (!cmd || !args || !*cmd)
		return (NULL);
	while (*cmd == ' ' || *cmd == '\t')
		++cmd;
	while (*cmd && *cmd != ';')
	{
		if (*cmd == '"' || *cmd == '\'')
			str = ft_strbetween(cmd, *cmd, *cmd);
		else if ((pos = ft_strpbrk_pos(cmd, " \t;")) != -1 || 1)
			str = (pos != -1 ? ft_strndup(cmd, pos) : ft_strdup(cmd));
		args->argv = ft_memjoin_clr(args->argv, sizeof(char *) * args->argc++,
			&str, sizeof(char *));
		cmd += ft_strlen(str) + (*cmd == '"' || *cmd == '\'' ? 2 : 0);
		while (*cmd == ' ' || *cmd == '\t')
			++cmd;
	}
	str = NULL;
	args->argv = ft_memjoin_clr(args->argv, sizeof(char *) * args->argc++,
		&str, sizeof(char *));
	return (*cmd == ';' ? cmd + 1 : cmd);
}

void	ft_delargs(t_args *args)
{
	int		i;

	if (!args)
		return ;
	i = 0;
	while (i < args->argc)
		free(args->argv[i++]);
	free(args->argv);
	args->argv = NULL;
	args->argc = 0;
}
