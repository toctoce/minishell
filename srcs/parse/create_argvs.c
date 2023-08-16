/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_argvs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:30:38 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/16 17:40:54 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void	init_argvs(t_argv **argvs, t_cmd **cmd, t_type **type)
{
	t_argv	*argv;

	*cmd = malloc(sizeof(t_cmd) * 1);
	check_malloc_error(*cmd);
	(*cmd)->cnt = 0;
	(*cmd)->cmds = NULL;
	*type = malloc(sizeof(t_type));
	check_malloc_error(*type);
	(*type)->last = TK_NONE;
	(*type)->redir = TK_NONE;
	argv = create_argv();
	ft_argvadd_back(argvs, argv);
}

void	free_lst_only(t_list **lst)
{
	t_list	*to_free;
	t_list	*seek;

	seek = *lst;
	while (seek)
	{
		to_free = seek;
		seek = seek->next;
		if (to_free)
			free(to_free);
	}
	*lst = NULL;
}

void	create_argvs(t_argv **argvs, t_list *tokens, t_cmd **cmd, t_type **type)
{
	init_argvs(argvs, cmd, type);
	while (tokens)
	{
		add_argv(argvs, tokens->content, *cmd, *type);
		tokens = tokens->next;
	}
	add_cmd_to_argvs(*cmd, argvs);
	free(*cmd);
	free(*type);
}
