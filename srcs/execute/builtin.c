#include "../../includes/execute.h"

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
	if (ft_strcmp(cmd[0], "echo") == SUCCESS)
		run_echo(cmd);
	else if (ft_strcmp(cmd[0], "cd") == SUCCESS)
		run_cd(cmd);
	else if (ft_strcmp(cmd[0], "pwd") == SUCCESS)
		run_pwd(cmd);
	else if (ft_strcmp(cmd[0], "export") == SUCCESS)
		run_export(cmd);
	else if (ft_strcmp(cmd[0], "unset") == SUCCESS)
		run_unset(cmd);
	else if (ft_strcmp(cmd[0], "env") == SUCCESS)
		run_env(cmd);
	else if (ft_strcmp(cmd[0], "exit") == SUCCESS)
		run_exit(cmd);
	if (g_info.pid != getpid()) // 흠 pid가 다르면 종료?? 
		exit (SUCCESS);
	else
		g_info.last_exit_status = SUCCESS; // 이 부분 잘 모르겟누
}

void	single_process(t_argv *argv)
{
	int	origin_stdin;
	int	origin_stdout;

	origin_stdin = dup(STDIN_FILENO); // 표준입력 디스크립터를 origin_stdin에 저장
	origin_stdout = dup(STDOUT_FILENO); // 표준출력 디스크립터를 origin_stdout에 저장
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
