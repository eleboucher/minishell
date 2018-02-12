/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:49:26 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/07 18:01:30 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_arrdup(char **arr)
{
	int i;
	char **ret;

	i = -1;
	if (!(ret = (char**)malloc(sizeof(char*) * (ft_arrsize(arr) + 1))))
		return (NULL);
	ret[ft_arrsize(arr)] = 0;
	while (arr[++i])
		ret[i] = ft_strdup(arr[i]);
	return (ret);
}

int main(int argc, char **argv, char **environ)
{
	char *line;
	char **args;
	char **env;

	(void)argc;
	(void)argv;
	env	= ft_arrdup(environ);
	while(42)
	{
		ft_printf("$> ");
		if (get_next_line(0, &line) == -1)
			exit(EXIT_FAILURE);
		args = split_whitespaces(line);
		if (execute(args,env) == 0)
			exit(EXIT_FAILURE);
		freearr(&args);
		free(line);
	}
	exit(EXIT_SUCCESS);
}
