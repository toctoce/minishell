/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:24:37 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/16 18:04:47 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_str_list(char **str_list)
{
	char	**list_free;

	list_free = str_list;
	if (str_list == NULL)
		return ;
	while (*str_list)
	{
		free(*str_list);
		str_list++;
	}
	free(list_free);
}

void	free_lst(void *lst)
{
	free(((t_list *)lst)->content);
	free(lst);
}

void	free_content(void *content)
{
	free(content);
}

void	free_dummy(void *dummy)
{
	free(((t_dummy *)dummy)->value);
	free(dummy);
}

void	free_token(void *token)
{
	free(((t_token *)token)->value);
	free(token);
}
