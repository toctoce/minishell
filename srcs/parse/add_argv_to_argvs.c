/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_argv_to_argvs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:49:34 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/15 18:39:56 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	add_word(t_argv **argvs, t_cmd *cmd, char *value, t_type *type)
{
	t_list	*new_cmd;

	if (type->redir == RD_T_OUT || type->redir == RD_A_OUT)
		ft_redirlast((*argvs)->out)->value = value;
	else if (type->redir == RD_IN)
		ft_redirlast((*argvs)->in)->value = value;
	else if (type->redir == RD_HDOC)
	{
		(ft_redirlast((*argvs)->in)->value) = ft_strjoin("/tmp/.0", value);
		(ft_redirlast((*argvs)->hdoc)->value) = ft_strjoin("/tmp/.0", value);
		free(value);
	}
	else
	{
		new_cmd = ft_lstnew(value);
		check_malloc_error(new_cmd);
		ft_lstadd_back(&cmd->cmds, new_cmd);
		cmd->cnt += 1;
	}
	type->redir = TK_NONE;
	type->last = TK_WORD;
}

void	add_cmd_to_argvs(t_cmd *cmd, t_argv **argvs)
{
	t_list	*cmd_free;
	char	**cmds;
	int		idx;

	if (cmd->cnt == 0)
		return ;
	cmds = malloc(sizeof(char *) * (cmd->cnt + 1));
	check_malloc_error(cmds);
	ft_argvlast(*argvs)->cmd = cmds;
	cmd_free = cmd->cmds;
	idx = 0;
	while (idx < cmd->cnt)
	{
		cmds[idx] = ft_strdup(cmd->cmds->content);
		check_malloc_error(cmds[idx]);
		cmd->cmds = cmd->cmds->next;
		idx++;
	}
	cmds[idx] = NULL;
	ft_lstclear(&cmd_free, free_content);
	cmd->cnt = 0;
}

static void	add_pipe(t_argv **argvs, char *value, t_cmd *cmd, t_type *type)
{
	t_argv	*new_argv;

	add_cmd_to_argvs(cmd, argvs);
	new_argv = create_argv();
	ft_argvadd_back(argvs, new_argv);
	free(value);
	type->redir = TK_NONE;
	type->last = TK_PIPE;
}

static void	add_redir(t_argv **argvs, char *value, t_type *type)
{
	t_redir	*new;

	type->redir = get_redir_type(value);
	new = create_redir();
	new->type = type->redir;
	if (type->redir == RD_T_OUT || type->redir == RD_A_OUT)
		ft_rediradd_back(&(*argvs)->out, new);
	else
		ft_rediradd_back(&(*argvs)->in, new);
	if (type->redir == RD_HDOC)
	{
		new = create_redir();
		new->type = type->redir;
		ft_rediradd_back(&(*argvs)->hdoc, new);
	}
	free(value);
	type->last = TK_REDIR;
}

void	add_argv(t_argv **argvs, t_token *token, t_cmd *cmd, t_type *type)
{
	t_argv	*argv_last;

	argv_last = ft_argvlast(*argvs);
	if (token->type == TK_WORD)
		add_word(&argv_last, cmd, token->value, type);
	else if (token->type == TK_PIPE)
		add_pipe(argvs, token->value, cmd, type);
	else if (token->type == TK_REDIR)
		add_redir(&argv_last, token->value, type);
}
