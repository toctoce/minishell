#include "../../includes/minishell.h"

static void	change_flag(char ***cmd, int *flag, char **tmp, int idx1)
{
	if (idx1 != 0)
	{
		*flag = TRUE;
		*cmd = &tmp[idx1];
	}
}

static void	check_option(char ***cmd, int *flag) // echo -n 개행 출력 x
{
	int		idx1;
	int		idx2;
	char	**tmp;

	idx1 = 0;
	idx2 = 0;
	(*cmd)++;
	tmp = *cmd;
	*flag = FALSE;
	while (tmp[idx1] && tmp[idx1][idx2] == '-')
	{
		if (tmp[idx1][idx2] == '-' && tmp[idx1][idx2 + 1] == 'n')
		{
			idx2++;
			while (tmp[idx1][idx2] == 'n')
				idx2++;
		}
		if (tmp[idx1][idx2])
			break ;
		idx1++;
		idx2 = 0;
	}
	change_flag(cmd, flag, tmp, idx1);
}

void	run_echo(char **cmd)
{
	int		idx;
	int		flag;

	check_option(&cmd, &flag);
	idx = 0;
	while (cmd[idx])
	{
		ft_putstr_fd(cmd[idx], STDOUT_FILENO);
		if (cmd[idx + 1])
			ft_putchar_fd(' ', STDOUT_FILENO);
		idx++;
	}
	if (flag == FALSE)
		ft_putchar_fd('\n', STDOUT_FILENO);
}
