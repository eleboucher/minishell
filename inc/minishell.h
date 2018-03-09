/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 15:50:26 by elebouch          #+#    #+#             */
/*   Updated: 2018/03/09 14:50:15 by elebouch         ###   ########.fr       */
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

typedef struct		s_args
{
	int				argc;
	char			**argv;
}					t_args;

typedef	struct		s_cmd
{
	char			*cmd;
	char			*bin;
	char			*path;
}					t_cmd;

char				*ft_getargs(char *cmd, t_args *args);
void				ft_delargs(t_args *args);
void				freearr(char ***arr);
int					execute(t_args *args, char ***env);
int					cmd_launch(t_cmd *data, char **args, char **env);
int					bltin_echo(char **args, char ***env);
int					bltin_cd(char **args, char ***env);
int					bltin_exit(char **args, char ***env);
int					bltin_setenv(char **args, char ***env);
int					bltin_unsetenv(char **args, char ***env);
int					bltin_env(char **args, char ***env);
void				print_fromenv(char **env, char *var);
int					get_index_fromenv(char **env, char *var);
char				**realloc_env(char **env, int size);
char				*get_fromenv(char **env, char *var);
void				change_env(char ***env, char *var, char *value);
void				changedir(char *path, char ***env);
#endif
