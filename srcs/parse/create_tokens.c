/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:24:27 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/11 18:24:28 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

#include "../../includes/parse.h"

static int	get_read_size(t_dummy_info dummy, char *line)
{
	int	read_size;

	read_size = line - dummy.addr;
	if (dummy.type & DUMMY_QUOTE)
		read_size = read_size + 1;
	return (read_size);
}

static int	get_dummy_size(t_dummy_info dummy, char *line)
{
	int	size;

	size = line - dummy.addr;
	if (dummy.type & DUMMY_SPACE)
		size = 0;
	if (dummy.type & (DUMMY_PIPE | DUMMY_REDIR))
		size = 1;
	else if (dummy.type & DUMMY_QUOTE && dummy.type & DUMMY_END)
		size = size - 1;
	return (size);
}

static int	dummy_type(char c)
{
	if (c == '\'')
		return (DUMMY_S_QUOTE);
	else if (c == '"')
		return (DUMMY_D_QUOTE);
	else if (c == '<')
		return (DUMMY_L_REDIR);
	else if (c == '>')
		return (DUMMY_R_REDIR);
	else if (c == '|')
		return (DUMMY_PIPE);
	else if (ft_isspace(c))
		return (DUMMY_SPACE);
	else
		return (DUMMY_CHAR);
}

static int	update_dummy_type(t_dummy_info dummy, char c)
{
	if (dummy.type & (DUMMY_QUOTE | DUMMY_CHAR) && (c == '>' || c == '<' || c == '|'))
		dummy.type ^= DUMMY_ADD_NULL;
	else if (dummy.type & DUMMY_L_REDIR && (!is_wspace(c) && c != '<'))
		dummy.type ^= DUMMY_ADD_NULL;
	else if (dummy.type & DUMMY_R_REDIR && (!is_wspace(c) && c != '>'))
		dummy.type ^= DUMMY_ADD_NULL;
	else if (dummy.type & DUMMY_PIPE || dummy.type & DUMMY_SPACE)
		dummy.type ^= DUMMY_ADD_NULL;
	return (dummy.type);
}

int	search_dummy(t_dummy_info *dummy, char **line)
{
	int	read_size;

	dummy->type = dummy_type(**line);
	if (dummy->type & DUMMY_QUOTE)
		*line += 1;
	dummy->addr = *line;
	while (**line && !(dummy->type & DUMMY_END))
	{
		if (dummy->type & DUMMY_CHAR && dummy_type(**line) != DUMMY_CHAR)
			break ; // ###### 왜 얘만 break인 것이냐
		if (dummy->type & DUMMY_S_QUOTE && **line == '\'')
			dummy->type ^= DUMMY_END;
		if (dummy->type & DUMMY_D_QUOTE && **line == '"')
			dummy->type ^= DUMMY_END;
		if (dummy->type & (DUMMY_SPACE | DUMMY_PIPE) && !ft_isspace(*(*line + 1)))
			dummy->type ^= DUMMY_END;
		if (dummy->type & DUMMY_REDIR)
			dummy->type ^= DUMMY_END;
		(*line)++;
	}
	read_size = get_read_size(*dummy, line); // 따옴표 포함 길이
	dummy->size = get_dummy_size(*dummy, line); // 따옴표 제외 길이
	dummy->type = update_dummy_type(*dummy, *line); // e_dummy_type 중에 뭔지 넣어줌.
	return (read_size);
}


static int	create_dummies(t_list **dummys, char *line)
{
	t_list			*dummy;
	t_dummy_info	dummy_info;

	while (ft_isspace(*line))
		line++;
	while (*line) // 한 단어(더미)마다 수행
	{
		search_dummy(&dummy_info, &line); // line 가지고 따옴표 있는지, 길이는 얼마나 되는지 체크
		dummy = create_dummy(dummy_info.addr, dummy_info.size, dummy_info.type);
// 		if (!dummy)
// 			return (FAIL);
// 		if (dummy_info.type & DUMMY_ADD_NULL)
// 		{
// 			dummy->next = create_dummy(NULL, 1, 0);
// 			if (!dummy->next)
// 				return (FAIL);
// 		}
// 		ft_lstadd_back(dummys, dummy);
	}
// 	return (SUCCESS);
}

int	create_tokens(t_list **tokens, t_list **dummys, char *line)
{
	t_list	*token;
	t_list	*seek;

	if (create_dummies(dummys, line)) // 더미로 담아버리기~
		return (ERROR_DUMMIES);
	print(line);print("\n");
	// seek = *dummys;
	// while (seek)
	// {
	// 	token = dummies_to_token(&seek); // 토큰으로 담아버리기~
	// 	if (!token)
	// 		return (ERROR_DUMMIES | ERROR_TOKENS);
	// 	ft_lstadd_back(tokens, token);
	// }
	// if (!*dummys)
	// 	return (FAIL);
	// if (check_syntax(*tokens)) // 그 토큰으로 문법 체크
	// 	return (ERROR_DUMMIES | ERROR_TOKENS | ERROR_SYNTAX);
	// return (SUCCESS);
}
