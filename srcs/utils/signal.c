#include "../../includes/minishell.h"

void	hdoc_sigint_handler(int signo)
{
	(void)signo;
	ft_putendl_fd("", STDOUT_FILENO);
	exit(FAIL);
}

void	ignore_signal(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	default_signal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}