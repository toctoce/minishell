/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multi_proc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:35:43 by dohyunki          #+#    #+#             */
/*   Updated: 2023/08/16 17:42:42 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	set_child_exit(int status)
{
	if (status == 2)
	{
		printf("\n");
		g_info.last_exit_status = status + 128;
	}
	else if (status == 3)
	{
		printf("Quit: %d\n", status);
		g_info.last_exit_status = status + 128;
	}
	else
		g_info.last_exit_status = status >> 8;
}

static void	wait_childs(int cnt_pipe)
{
	int	idx;
	int	status;

	idx = 0;
	status = 0;
	while (idx < cnt_pipe + 1)
	{
		if (wait(&status) < 0)
			status = 1;
		idx++;
	}
	set_child_exit(status);
}

static void	run_execve_process(char **cmd)
{
	char	*path;

	if (!cmd)
		exit(SUCCESS);
	path = get_path(*cmd);
	if (!path)
		print_error_exit(*cmd, "command not found", 127);
	if (execve(path, cmd, g_info.envp) == -1)
		print_error_exit(*cmd, strerror(errno), FAIL);
}

static void	run_child_process(t_argv *argv, int **pipes, int i)
{
	set_stdin_pipe(pipes, i - 1);
	set_stdout_pipe(argv, pipes, i);
	set_stdout_redir(argv);
	set_stdin_redir(argv);
	if (is_builtin(argv->cmd) == TRUE)
		run_builtin_process(argv->cmd);
	else
		run_execve_process(argv->cmd);
}

void	multi_process(t_argv *argv, pid_t *pids, int **pipes, int cnt_pipe)
{
	int		idx;
	t_argv	*tmp;

	idx = 0;
	tmp = argv;
	ignore_signal();
	while (idx < cnt_pipe + 1)
	{
		pids[idx] = fork();
		if (pids[idx] == 0)
		{
			default_signal();
			run_child_process(tmp, pipes, idx);
		}
		if (pids[idx] < 0)
		{
			print_error("fork", strerror(errno), FAIL);
			break ;
		}
		tmp = tmp->next;
		idx++;
	}
	close_pipes(pipes, cnt_pipe);
	wait_childs(cnt_pipe);
}
