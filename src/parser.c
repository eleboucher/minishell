/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:46:48 by elebouch          #+#    #+#             */
/*   Updated: 2018/05/06 10:08:09 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*handle_exp(char **cmd, char **env)
{
	char	*str;
	int		pos;
	char	*tldstr;
	char	*home;

	pos = ft_strpbrk_pos(*cmd, " \t\"'");
	if (!(str = (pos == -1 ? ft_strdup(*cmd) : ft_strndup(*cmd, pos))))
		return (NULL);
	if (str[0] == '~' && str[1] != '~' && env)
	{
		if (!(home = get_fromenv(env, "HOME")))
			return (NULL);
		if ((tldstr = ft_strjoin(home, str + 1)))
		{
			*cmd += (pos == -1 ? ft_strlen(*cmd) : (size_t)pos);
			free(str);
			return (tldstr);
		}
	}
	*cmd += (pos == -1 ? ft_strlen(*cmd) : (size_t)pos);
	return (str);
}

static char	*checkenvar(char *str, char **env)
{
	int		pos;
	char	*var;

	if ((pos = ft_strindexchr(str, '$')) != -1 && str[pos + 1])
	{
		if ((var = get_fromenv(env, &str[pos + 1])))
		{
			str[pos] = 0;
			str = ft_strjoin_clr(str, var, 0);
		}
	}
	return (str);
}

static char	*ft_checkargs(char **cmd, char **env)
{
	static char		*str;
	char			*ret;

	ret = NULL;
	str = ft_strnew(0);
	if (ft_strchr("\"'", **cmd))
	{
		ret = ft_strbetween(*cmd, **cmd, **cmd);
		if (*(*cmd += ft_strlen(ret) + 1))
			(*cmd)++;
		if (!(str = ft_strjoin_clr(str, ret, 2)))
			return (NULL);
	}
	else
	{
		if (!(ret = handle_exp(cmd, env)))
			return (NULL);
		if (!(str = ft_strjoin_clr(str, checkenvar(ret, env), 2)))
			return (NULL);
	}
	ret = str;
	str = NULL;
	return (ret);
}

char		*ft_getargs(char *cmd, t_args *args, char **env)
{
	char	*str;

	if (!cmd || !args || !*cmd)
		return (NULL);
	while (cmd && (*cmd == ' ' || *cmd == '\t'))
		++cmd;
	while (*cmd)
	{
		if (!(str = ft_checkargs(&cmd, env)))
			exit(EXIT_FAILURE);
		if (!(args->argv = ft_memjoin_clr(args->argv, sizeof(char *)
						* args->argc++, &str, sizeof(char *))))
			exit(EXIT_FAILURE);
		while (cmd && (*cmd == ' ' || *cmd == '\t'))
			++cmd;
	}
	str = NULL;
	if (!(args->argv = ft_memjoin_clr(args->argv, sizeof(char *) *
					args->argc++, &str, sizeof(char *))))
		exit(EXIT_FAILURE);
	return (cmd);
}

void		ft_delargs(t_args *args)
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
