/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:50:16 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/16 17:41:16 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	get_token_type(int type)
{
	if (type & DM_REDIR)
		return (TK_REDIR);
	if (type & DM_PIPE)
		return (TK_PIPE);
	return (TK_WORD);
}

static char	*get_token_value(t_list **dummies)
{
	t_dummy	*dummy;
	char	*value;

	if (((t_dummy *)((*dummies)->content))->type & (DM_NONE | DM_SPACE))
	{
		*dummies = (*dummies)->next;
		return (NULL);
	}
	value = ft_strdup("");
	while (*dummies)
	{
		dummy = (*dummies)->content;
		if (dummy->type & (DM_NONE | DM_SPACE))
		{
			*dummies = (*dummies)->next;
			break ;
		}
		value = gnl_strjoin_and_free(value, dummy->value);
		*dummies = (*dummies)->next;
	}
	return (value);
}

static void	add_dummies_to_tokens(t_list **tokens, t_list **dummies)
{
	t_token	*token;

	token = ft_calloc(1, sizeof(t_token));
	token->type = get_token_type(((t_dummy *)(*dummies)->content)->type);
	token->value = get_token_value(dummies);
	if (token->value)
		ft_lstadd_back(tokens, ft_lstnew(token));
	else
		free_token(token);
}

void	create_tokens(t_list **tokens, t_list *dummys)
{
	while (dummys)
		add_dummies_to_tokens(tokens, &dummys);
}
