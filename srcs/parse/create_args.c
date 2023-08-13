#include "../../includes/minishell.h"

static void	init_argvs(t_argv **argvs, t_cmd **cmd, t_type **type)
{
	t_argv	*argv;

    *cmd = malloc(sizeof(t_cmd) * 1);
    check_malloc_error(*cmd);
	(*cmd)->cnt = 0;
	(*cmd)->cmds = NULL;
	*type = (t_argv *)malloc(sizeof(t_argv));
    check_malloc_error(*type);
	(*type)->last = TK_NONE;
	(*type)->redir = TK_NONE;
	argv = (t_argv *)malloc(sizeof(t_argv));
    check_malloc_error(argv);
	argv->in = NULL;
	argv->out = NULL;
	argv->hdoc = NULL;
	argv->next = NULL;
	argv->cmd = NULL;
	ft_argvadd_back(argvs, argv);
	return (SUCCESS);
}

int	create_argvs(t_argv **argvs, t_list *tokens, t_cmd **cmd, t_type **type)
{
	init_argvs(argvs, cmd, type);
	while (tokens)
	{
		add_argv_to_argvs(argvs, tokens->content, *cmd, *type);
		tokens = tokens->next;
	}
	// if (put_cmd(*cmd, argvs))
	// 	return (ERROR_ARGVS);
	// free_lst_only(&(*cmd)->cmds);
	// free(*cmd);
	// free(*type);
	return (SUCCESS);
}
