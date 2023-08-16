/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:41:47 by dohyunki          #+#    #+#             */
/*   Updated: 2023/08/16 16:41:55 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	is_valid_command(char *cmd)
{
	struct stat	info;

	if (stat(cmd, &info) == 0)
	{
		if ((info.st_mode & S_IFMT) == S_IFDIR)
			print_error_exit(cmd, "is a directory", 126);
		return (TRUE);
	}
	return (FALSE);
}

static int	is_valid_path(char *path)
{
	if (!*path || !ft_strcmp(path, ".") || !ft_strcmp(path, ".."))
		print_error_exit(path, "command not found", 127);
	if (!ft_strchr(path, '/'))
		return (FALSE);
	is_valid_command(path);
	return (TRUE);
}

static char	*make_path(char *cmd, char **paths)
{
	char		*path;
	int			i;

	i = -1;
	while (paths[++i])
	{
		path = ft_str_double_join(paths[i], "/", cmd);
		if (is_valid_command(path))
			return (path);
	}
	free(path);
	return (NULL);
}

char	*get_path(char *cmd)
{
	t_env	*env_path;
	char	**paths;

	if (is_valid_path(cmd))
		return (cmd);
	env_path = get_env("PATH");
	if (!env_path)
		print_error_exit(cmd, "No such file or directory", FAIL);
	paths = ft_split(env_path->value, ':');
	if (!paths)
		exit (FAIL);
	return (make_path(cmd, paths));
}
