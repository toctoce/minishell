#include "../../includes/minishell.h"

void	set_stdin_pipe(int **pipes, int num)
{
	int	i;

	i = -1;
	if (!pipes)
		return ;
	if (num < 0)
	{
		while (pipes[++i])
			close(pipes[i][0]);
		return ;
	}
	dup2(pipes[num][0], STDIN_FILENO);
	while (pipes[++i])
		close(pipes[i][0]);
}

void	set_stdout_pipe(t_argv *argv, int **pipes, int num)
{
	int	i;

	i = -1;
	if (!pipes)
		return ;
	if (!argv->next)
	{
		while (pipes[++i])
			close(pipes[i][1]);
		return ;
	}
	dup2(pipes[num][1], STDOUT_FILENO);
	while (pipes[++i])
		close(pipes[i][1]);
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
