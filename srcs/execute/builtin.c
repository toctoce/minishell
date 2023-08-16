/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:41:25 by dohyunki          #+#    #+#             */
/*   Updated: 2023/08/16 16:43:39 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_builtin(char **cmd)
{
	int			idx;
	const char	*builtins_cmd[7] = {"echo", "cd", "pwd", "export",
		"unset", "env", "exit"};

	if (!cmd)
		return (FALSE);
	idx = 0;
	while (idx < 7)
	{
		if (ft_strcmp(*cmd, builtins_cmd[idx]) == 0)
			return (TRUE);
		idx++;
	}
	return (FALSE);
}

void	run_builtin_process(char **cmd)
{
	if (ft_strcmp(cmd[0], "echo") == 0)
		run_echo(cmd);
	else if (ft_strcmp(cmd[0], "cd") == 0)
		run_cd(cmd);
	else if (ft_strcmp(cmd[0], "pwd") == 0)
		run_pwd(cmd);
	else if (ft_strcmp(cmd[0], "export") == 0)
		run_export(cmd);
	else if (ft_strcmp(cmd[0], "unset") == 0)
		run_unset(cmd);
	else if (ft_strcmp(cmd[0], "env") == 0)
		run_env(cmd);
	else if (ft_strcmp(cmd[0], "exit") == 0)
		run_exit(cmd);
	if (g_info.pid != getpid())
		exit(EXIT_STATUS_SUCCESS);
	else
		g_info.last_exit_status = EXIT_STATUS_SUCCESS;
}

void	single_process(t_argv *argv)
{
	int	origin_stdin;
	int	origin_stdout;

	origin_stdin = dup(STDIN_FILENO);
	origin_stdout = dup(STDOUT_FILENO);
	if (set_stdout_redir(argv) == FAIL || set_stdin_redir(argv) == FAIL)
	{
		reset_stdin(origin_stdin);
		reset_stdout(origin_stdout);
		return ;
	}
	run_builtin_process(argv->cmd);
	reset_stdin(origin_stdin);
	reset_stdout(origin_stdout);
}
