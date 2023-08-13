#include "../../includes/minishell.h"

// int	put_cmd(t_cmd *cmd, t_argv **argvs)
// {
// 	t_list	*h_cmd;
// 	char	**arr;
// 	int		i;

// 	if (!cmd->cnt)
// 		return (SUCCESS);
// 	arr = malloc(sizeof(char *) * (cmd->cnt + 1));
// 	if (!arr)
// 		return (FAIL);
// 	ft_argvlast(*argvs)->cmd = arr;
// 	h_cmd = cmd->cmds;
// 	i = -1;
// 	while (++i < cmd->cnt)
// 	{
// 		arr[i] = ft_strdup(cmd->cmds->content);
// 		if (!arr[i])
// 			return (FAIL);
// 		cmd->cmds = cmd->cmds->next;
// 	}
// 	arr[i] = NULL;
// 	ft_lstclear(&h_cmd, free_content);
// 	cmd->cnt = 0;
// 	return (SUCCESS);
// }

// static int	add_pipe(t_argv **argvs, char *value, t_cmd *cmd, t_type *type)
// {
// 	t_argv	*new_argv;

// 	if (put_cmd(cmd, argvs))
// 		return (FAIL);
// 	new_argv = create_argv();
//     check_malloc_error(new_argv);
// 	ft_argvadd_back(argvs, new_argv);
// 	free(value);
// 	type->redir = TK_NONE;
// 	type->last = TK_PIPE;
// 	return (SUCCESS);
// }

void	add_argv_to_argvs(t_argv **argvs, t_token *token, t_cmd *cmd, t_type *type)
{
	t_argv	*argv_last;

	argv_last = ft_argvlast(*argvs);
	if (token->type == TK_PIPE)
		add_pipe(argvs, token->value, cmd, type);
	// else if (token->type == TK_REDIR)
	// 	add_redir(&argv_last, token->value, type);
	// else if (token->type == TK_WORD)
	// 	add_word(&argv_last, cmd, token->value, type);
}