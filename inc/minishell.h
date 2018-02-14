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
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include "get_next_line.h"
# include "ft_printf.h"


typedef	struct		s_cmd
{
		char		*cmd;
		char		*bin;
		char		*path;
}					t_cmd;

char	**split_whitespaces(char const *s);
void	freearr(char ***arr);
int		execute(char **args, char **env);
int		cmd_launch(t_cmd *data, char **args, char **env);
int		bltin_echo(char **args);
int 	bltin_cd(char **args);
int		bltin_exit(char **args);
int		bltin_setenv(char **args);
int		bltin_unsetenv(char **args);
int 	bltin_env(char **args);
#endif