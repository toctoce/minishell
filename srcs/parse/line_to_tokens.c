/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_to_tokens.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:24:27 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/13 01:18:25 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// void print_type(int type)
// {
// 	if (type & DM_NONE)
// 		ft_putstr_fd("NONE ", 1);
// 	if (type & DM_CHAR)
// 		ft_putstr_fd("CHAR ", 1);
// 	if (type & DM_S_QUOTE)
// 		ft_putstr_fd("S_QUOTE ", 1);
// 	if (type & DM_D_QUOTE)
// 		ft_putstr_fd("D_QUOTE ", 1);
// 	if (type & DM_REDIR)
// 		ft_putstr_fd("REDIR ", 1);
// 	if (type & DM_PIPE)
// 		ft_putstr_fd("PIPE ", 1);
// 	if (type & DM_SPACE)
// 		ft_putstr_fd("SPACE ", 1);
// 	if (type & DM_END)
// 		ft_putstr_fd("END ", 1);
// 	if (type & DM_ADD_NULL)
// 		ft_putstr_fd("ADD_NULL ", 1);
// 	ft_putendl_fd("", 1);
// }
// void print_type2(int type)
// {
// 	if (type == TK_NONE)
// 		ft_putstr_fd("NONE ", 1);
// 	if (type == TK_PIPE)
// 		ft_putstr_fd("PIPE ", 1);
// 	if (type == TK_REDIR)
// 		ft_putstr_fd("REDIR ", 1);
// 	if (type == TK_WORD)
// 		ft_putstr_fd("WORD ", 1);
// 	ft_putendl_fd("", 1);
// }

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
	if (create_dummies(dummys, line) == FAIL) // 더미로 담아버리기~
		return (ERROR_DUMMIES);
	// // 프린트
	// t_list *du;
	// du = *dummys;
	// while (du)
	// {
	// 	print("----dummy---");
	// 	if ((((t_dummy *)(du)->content)->type) & DM_NONE)
	// 		print("null");
	// 	else if (((t_dummy *)(du)->content)->value)
	// 	{
	// 		print(((t_dummy *)(du)->content)->value);
	// 		print(ft_itoa(ft_strlen(((t_dummy *)(du)->content)->value)));
	// 		print_type(((t_dummy *)(du)->content)->type);
	// 	}
	// 	else
	// 		print("else");
	// 	(du) = (du)->next;
	// }
	// // 프린트 끝
	create_tokens(tokens, *dummys);
	// // 프린트
	// t_list *to;
	// to = *tokens;
	// while (to)
	// {
	// 	print("----tokens---");
	// 	if (!(((t_token *)to->content)->value))
	// 		print("null");
	// 	if (((t_token *)to->content)->value)
	// 	{
	// 		print(((t_token *)to->content)->value);
	// 		print_type2(((t_token *)to->content)->type);
	// 	}
	// 	to = to->next;
	// }
	// // 프린트 끝
	if (valid_syntax(*tokens) == FALSE) // 그 토큰으로 문법 체크
		return (ERROR_SYNTAX);
	return (ERROR_NO_OCCURED);
}
