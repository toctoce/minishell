/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:42:03 by dohyunki          #+#    #+#             */
/*   Updated: 2023/08/16 16:46:17 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	update_env_pwds(char *cwd)
{
	t_env	*old_pwd;
	t_env	*pwd;

	old_pwd = get_env("OLDPWD");
	pwd = get_env("PWD");
	if (old_pwd)
	{
		free(old_pwd->value);
		if (!pwd)
			old_pwd->value = ft_strdup("");
		else
			old_pwd->value = ft_strdup(pwd->value);
		if (!old_pwd->value)
			print_error_exit("malloc", strerror(errno), FAIL);
	}
	if (pwd)
	{
		free(pwd->value);
		pwd->value = ft_strdup(cwd);
		if (!pwd->value)
			print_error_exit("malloc", strerror(errno), FAIL);
	}
}

void	run_cd(char **cmd)
{
	char	cwd[PATH_MAX];

	if (!cmd[1])
		return ;
	if (cmd[2])
	{
		print_error("cd", "too many arguments", FAIL);
		return ;
	}
	if (chdir(cmd[1]) != 0)
	{
		print_error(ft_str_double_join("cd", ": ", \
					cmd[1]), strerror(errno), FAIL);
		return ;
	}
	if (!getcwd(cwd, sizeof(cwd)))
	{
		print_error("cd", strerror(errno), FAIL);
		return ;
	}
	update_env_pwds(cwd);
	reset_envp();
}
