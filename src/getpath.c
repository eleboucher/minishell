/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getpath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elebouch <elebouch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 09:07:41 by elebouch          #+#    #+#             */
/*   Updated: 2018/05/16 15:31:28 by elebouch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char		*skip_slash(char *str)
{
	while (*str && *str == '/')
		str++;
	return (str);
}

static void		prev_path(char *str, int *len)
{
	if (!*len)
		return ;
	(*len)--;
	if (*len)
	{
		str[*len] = '\0';
		(*len)--;
	}
	else
		return ;
	while (*len > 0 && str[*len] != '/')
	{
		str[*len] = '\0';
		(*len)--;
	}
}

static char		*cleanpath(char *path)
{
	char	*str;
	int		len;

	if (!(str = ft_strnew(MAXPATHLEN)))
		return (NULL);
	len = 0;
	while (*path && len < MAXPATHLEN)
	{
		if (*path == '/') 
		{
			path = skip_slash(path);
			str[len++] = '/';
		}
		else if (!ft_strncmp(path, "./", 2) || !ft_strcmp(path, "."))
			path = skip_slash(path + 1);
		else if (!ft_strncmp(path, "..", 2))
		{
			prev_path(str, &len);
			path += 2;
		}
		else
			str[len++] = *(path++);
	}
	return (str);
}

char			*get_cd_path(char *path, char *pwd)
{
	char	*tmp;
	char	*ret;

	if (path && path[0] == '/')
		return (cleanpath(path));
	if (!pwd)
		tmp = ft_strdup(path);
	else
	{
		tmp = ft_strjoin(pwd, "/");
		tmp = ft_strjoin_clr(tmp, path, 0);
	}
	ret = cleanpath(tmp);
	free(tmp);
	return (ret);
}
