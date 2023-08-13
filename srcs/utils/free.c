/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:24:37 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/13 03:48:33 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

// void	free_lst_only(t_list **lst)
// {
// 	t_list	*to_free;
// 	t_list	*seek;

// 	seek = *lst;
// 	while (seek)
// 	{
// 		to_free = seek;
// 		seek = seek->next;
// 		if (to_free)
// 			free(to_free);
// 	}
// 	*lst = NULL;
// }

void	free_content(void *content)
{
	free(content);
}

void	free_dummy(t_dummy *dummy)
{
    free(dummy->value);
	free(dummy);
}

void	free_token(t_token *token)
{
    free(token->value);
	free(token);
}
