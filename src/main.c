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

int main(void)
{
	char *line;
	char **args;

	while(42)
	{
		ft_printf("$> ");
		if (get_next_line(0, &line) == -1)
			exit(EXIT_FAILURE);
		args = split_whitespaces(line);
		if (execute(args) == 0)
			exit(EXIT_FAILURE);
		freearr(&args);
		free(line);
	}
	exit(EXIT_SUCCESS);
}
