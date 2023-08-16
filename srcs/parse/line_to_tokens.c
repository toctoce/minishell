/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:24:27 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/16 17:42:10 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	get_redir_type(char *value)
{
	if (ft_strcmp(value, ">") == 0)
		return (RD_T_OUT);
	else if (ft_strcmp(value, ">>") == 0)
		return (RD_A_OUT);
	else if (ft_strcmp(value, "<") == 0)
		return (RD_IN);
	else if (ft_strcmp(value, "<<") == 0)
		return (RD_HDOC);
	return (RD_NONE);
}

static int	valid_syntax(t_list	*tokens)
{
	t_token	*token;
	int		last_type;

	last_type = TK_NONE;
	while (tokens)
	{
		token = (t_token *)tokens->content;
		if (last_type == TK_NONE && token->type == TK_PIPE)
			return (FALSE);
		if (last_type == TK_REDIR && token->type != TK_WORD)
			return (FALSE);
		if (last_type == TK_PIPE && token->type == TK_PIPE)
			return (FALSE);
		if (token->type == TK_REDIR && get_redir_type(token->value) == RD_NONE)
			return (FALSE);
		last_type = token->type;
		tokens = tokens->next;
	}
	if (last_type != TK_WORD)
		return (FALSE);
	return (TRUE);
}

int	line_to_tokens(t_list **tokens, t_list **dummys, char *line)
{
	if (create_dummies(dummys, line) == FAIL)
		return (ERROR_DUMMIES);
	create_tokens(tokens, *dummys);
	ft_lstclear(dummys, free_dummy);
	if (valid_syntax(*tokens) == FALSE)
		return (ERROR_SYNTAX);
	return (ERROR_NO_OCCURED);
}
