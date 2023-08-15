#include "../../includes/minishell.h"

void	run_pwd(char **cmd)
{
	char	cwd[PATH_MAX];

	if (cmd[1])
	{
		print_error("pwd", "too many arguments", FAIL);
		return ;
	}
	if (!getcwd(cwd, sizeof(cwd)))
	{
		print_error("pwd", strerror(errno), FAIL);
		return ;
	}
	printf("%s\n", cwd);
}
