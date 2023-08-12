/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dummies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:08:41 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/12 20:33:36 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static int	dummy_type(char c)
{
	if (c == '\'')
		return (DM_S_QUOTE);
	else if (c == '"')
		return (DM_D_QUOTE);
	else if (c == '<')
		return (DM_L_REDIR);
	else if (c == '>')
		return (DM_R_REDIR);
	else if (c == '|')
		return (DM_PIPE);
	else if (ft_isspace(c))
		return (DM_SPACE);
	else
		return (DM_CHAR);
}

static void	set_dummy_info(t_dummy_info **dummy, char *line)
{
	if ((*dummy)->type & DM_SPACE)
		(*dummy)->size = 0;
	else if ((*dummy)->type & (DM_PIPE | DM_REDIR))
		(*dummy)->size = 1;
	else if ((*dummy)->type & DM_QUOTE && (*dummy)->type & DM_END)
		(*dummy)->size = line - (*dummy)->addr - 1;
	else
		(*dummy)->size = line - (*dummy)->addr;
	if ((*dummy)->type & (DM_QUOTE | DM_CHAR) && (*line == '>' || *line == '<' || *line == '|'))
		(*dummy)->type ^= DM_ADD_NULL;
	else if ((*dummy)->type & DM_L_REDIR && (!ft_isspace(*line) && *line != '<'))
		(*dummy)->type ^= DM_ADD_NULL;
	else if ((*dummy)->type & DM_R_REDIR && (!ft_isspace(*line) && *line != '>'))
		(*dummy)->type ^= DM_ADD_NULL;
	else if ((*dummy)->type & DM_PIPE || (*dummy)->type & DM_SPACE)
		(*dummy)->type ^= DM_ADD_NULL;
}

static t_dummy_info	*create_dummy(char **line)
{
	t_dummy_info	*dummy;

	dummy = malloc(sizeof(t_dummy_info));
	dummy->type = dummy_type(**line);
	if (dummy->type & DM_QUOTE)
		*line += 1;
	dummy->addr = *line;
	while (**line && !(dummy->type & DM_END))
	{
		if (dummy->type & DM_CHAR && !(dummy_type(*(*line + 1)) & DM_CHAR))
			dummy->type ^= DM_END;
		if (dummy->type & DM_SPACE && !(dummy_type(*(*line + 1)) & DM_SPACE))
			dummy->type ^= DM_END;
		if (dummy->type & (DM_PIPE | DM_REDIR))
			dummy->type ^= DM_END;
		if (dummy->type & DM_S_QUOTE && dummy_type(**line) & DM_S_QUOTE)
			dummy->type ^= DM_END;
		if (dummy->type & DM_D_QUOTE && dummy_type(**line) & DM_D_QUOTE)
			dummy->type ^= DM_END;
		(*line)++;
	}
	set_dummy_info(&dummy, *line);
	return (dummy);
}

static void	add_dummy_to_dummy_list(t_list **dummy_list, t_dummy_info *dummy_info)
{
	t_list			*new_dummy;
	t_dummy_info	*dummy_null;

	new_dummy = ft_lstnew(dummy_info);
	if (!new_dummy)
		exit_shell_by_error("malloc error");
	ft_lstadd_back(dummy_list, new_dummy);
	if (dummy_info->type & DM_ADD_NULL)
	{
		dummy_null = malloc(sizeof(t_dummy_info));
		dummy_null->addr = NULL;
		dummy_null->size = 1;
		dummy_null->type = DM_NONE;
		ft_lstadd_back(dummy_list, ft_lstnew(dummy_null));
	}
}


void	create_dummies(t_list **dummy_list, char *line)
{
	t_list			*dummy;
	t_dummy_info	*dummy_info;

	while (ft_isspace(*line))
		line++;
	while (*line) // 한 단어(더미)마다 수행
	{
		dummy_info = create_dummy(&line); // line 가지고 따옴표 있는지, 길이는 얼마나 되는지 체크
		add_dummy_to_dummy_list(dummy_list, dummy_info);
	}
}