/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:50:26 by elebouch          #+#    #+#             */
/*   Updated: 2018/02/07 18:31:34 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdlib.h>
# include <sys/wait.h>
# include <unistd.h>
# include "get_next_line.h"
# include "ft_printf.h"

char	**split_whitespaces(char const *s);
void	freearr(char ***arr);
int		execute(char **args);
int		cmd_launch(char **args);
int		bltin_echo(char **args);
int 	bltin_cd(char **args);
int		bltin_exit(char **args);
int		bltin_setenv(char **args);
int		bltin_unsetenv(char **args);
int 	bltin_env(char **args);
#endif
