/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dummies.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 20:08:41 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/16 18:07:30 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"
// void print_type(int type);

static int	get_dummy_type(char c)
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
	if ((*dummy)->type & (DM_QUOTE | DM_CHAR) && \
		(*line == '>' || *line == '<' || *line == '|'))
		(*dummy)->type ^= DM_ADD_NULL;
	else if ((*dummy)->type & DM_L_REDIR && \
		(!ft_isspace(*line) && *line != '<'))
		(*dummy)->type ^= DM_ADD_NULL;
	else if ((*dummy)->type & DM_R_REDIR && \
		(!ft_isspace(*line) && *line != '>'))
		(*dummy)->type ^= DM_ADD_NULL;
	else if ((*dummy)->type & DM_PIPE || (*dummy)->type & DM_SPACE)
		(*dummy)->type ^= DM_ADD_NULL;
}

static t_dummy_info	*create_dummy(char **line)
{
	t_dummy_info	*dummy;

	dummy = malloc(sizeof(t_dummy_info));
	dummy->type = get_dummy_type(**line);
	if (dummy->type & DM_QUOTE)
		*line += 1;
	dummy->addr = *line;
	while (**line && !(dummy->type & DM_END))
	{
		if (dummy->type & DM_CHAR && get_dummy_type(*(*line + 1)) != DM_CHAR)
			dummy->type ^= DM_END;
		if (dummy->type & DM_SPACE && get_dummy_type(*(*line + 1)) != DM_SPACE)
			dummy->type ^= DM_END;
		if (dummy->type & (DM_PIPE | DM_REDIR))
			dummy->type ^= DM_END;
		if (dummy->type & DM_S_QUOTE && get_dummy_type(**line) == DM_S_QUOTE)
			dummy->type ^= DM_END;
		if (dummy->type & DM_D_QUOTE && get_dummy_type(**line) == DM_D_QUOTE)
			dummy->type ^= DM_END;
		(*line)++;
	}
	set_dummy_info(&dummy, *line);
	return (dummy);
}

static void	add_dummy_to_dummies(t_list **dummys, t_dummy_info *dummy_info)
{
	t_dummy	*dummy;
	t_dummy	*dummy_null;

	dummy = malloc(sizeof(t_dummy) * 1);
	if (!dummy)
		exit_shell_by_error("malloc failed.");
	dummy->type = dummy_info->type;
	dummy->value = ft_strndup(dummy_info->addr, dummy_info->size);
	ft_lstadd_back(dummys, ft_lstnew(dummy));
	if (dummy_info->type & DM_ADD_NULL)
	{
		dummy_null = malloc(sizeof(t_dummy_info) * 1);
		if (!dummy_null)
			exit_shell_by_error("malloc failed.");
		dummy_null->type = DM_NONE;
		dummy_null->value = NULL;
		ft_lstadd_back(dummys, ft_lstnew(dummy_null));
	}
}

int	create_dummies(t_list **dummys, char *line)
{
	t_dummy_info	*dummy_info;

	while (ft_isspace(*line))
		line++;
	while (*line)
	{
		dummy_info = create_dummy(&line);
		if ((dummy_info->type & DM_QUOTE) && !(dummy_info->type & DM_END))
		{
			free(dummy_info);
			return (FAIL);
		}
		add_dummy_to_dummies(dummys, dummy_info);
	}
	free(dummy_info);
	return (SUCCESS);
}
