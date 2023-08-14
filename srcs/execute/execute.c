/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:24:15 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/11 22:40:55 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

static int	init_execute(int *cnt, pid_t **pids, int ***pipes, t_argv *argv)
{
	*pids = NULL;
	*pipes = NULL;
	set_pipe_cnt(cnt, argv); // 파이프 개수 체크
	*pids = (pid_t *)malloc(sizeof(pid_t) * (*cnt + 1));
	if (!(*pids))
		exit_shell_by_error("malloc failed");
	if (*cnt > 0)
	{
		if (set_pipes(pipes, *cnt) == FAIL)
			return (FAIL);
	}
	return (SUCCESS);
}

static void	end_execute(pid_t *pids, int **pipes, t_argv *argv)
{
	free(pids);
	free_pipes(pipes);
	unlink_hdoc(argv);
	free_argv(argv);
}

void	execute(t_argv *argv)
{
	int		cnt_pipe;
	int		**pipes;
	pid_t	pids;

	// if (check_heredoc(argv) == FALSE)
	//	return (free_argv(argv));
	set_echoctl();
	if (init_execute(&cnt_pipe, &pids, &pipes, argv) == FAIL)
	{
		g_info.last_exit_status = FAIL;
		return (end_execute(pids, pipes, argv));
	}
	if (cnt_pipe == 0 && is_builtin(argv->cmd) == TRUE)
		single_process(argv);
	else
		// multi_process(argv);
	end_execute(pids, pipes, argv);
}
