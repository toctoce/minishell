#include "../../includes/minishell.h"

void	free_argv(t_argv *argv)
{
	t_argv	*tmp;

	tmp = argv;
	while (argv)
	{
		free_redir(tmp->in);
		free_redir(tmp->out);
		free_redir(tmp->hdoc);
		free_strs(tmp->cmd);
		tmp = argv->next;
		free(argv);
		argv = tmp;
	}
}

int	ft_argvsize(t_argv *argvs)
{
	int	len;

	len = 0;
	while (argvs)
	{
		len++;
		argvs = argvs->next;
	}
	return (len);
}

t_argv	*ft_argvlast(t_argv *argv)
{
	while (ft_argvsize(argv) > 1)
		argv = argv->next;
	return (argv);
}

void	ft_argvadd_back(t_argv **argvs, t_argv *new)
{
	if (!*argvs)
		*argvs = new;
	else
		ft_argvlast(*argvs)->next = new;
}