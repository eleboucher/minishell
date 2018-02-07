/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:00:43 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/07 18:14:05 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		freearr(char ***arr)
{
	char	**file_name;
	int		i;

	file_name = *arr;
	i = -1;
	while (file_name[++i])
		free(file_name[i]);
	free(file_name);
}
