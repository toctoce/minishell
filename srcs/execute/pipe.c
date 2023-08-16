/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:41:58 by dohyunki          #+#    #+#             */
/*   Updated: 2023/08/16 16:46:02 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	set_stdin_pipe(int **pipes, int num)
{
	int	idx;

	idx = 0;
	if (!pipes)
		return ;
	if (num < 0)
	{
		while (pipes[idx])
		{
			close(pipes[idx][0]);
			idx++;
		}
		return ;
	}
	dup2(pipes[num][0], STDIN_FILENO);
	while (pipes[idx])
	{
		close(pipes[idx][0]);
		idx++;
	}
}

void	set_stdout_pipe(t_argv *argv, int **pipes, int num)
{
	int	idx;

	idx = 0;
	if (!pipes)
		return ;
	if (!argv->next)
	{
		while (pipes[idx])
		{
			close(pipes[idx][1]);
			idx++;
		}
		return ;
	}
	dup2(pipes[num][1], STDOUT_FILENO);
	while (pipes[idx])
	{
		close(pipes[idx][1]);
		idx++;
	}
}

void	close_pipes(int **pipes, int cnt)
{
	int	idx;

	if (!pipes)
		return ;
	idx = 0;
	while (idx < cnt)
	{
		close(pipes[idx][0]);
		close(pipes[idx][1]);
		idx++;
	}
}

void	free_pipes(int **pipes)
{
	int	idx;

	if (!pipes)
		return ;
	idx = 0;
	while (pipes[idx])
	{
		free(pipes[idx]);
		idx++;
	}
	free(pipes);
}
