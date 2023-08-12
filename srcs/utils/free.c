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

// void	free_content(void *content)
// {
// 	free(content);
// }

void	free_dummy(void *content)
{
	t_dummy	*dummy;

	dummy = (t_dummy *)content;
    free(dummy->value);
	free(dummy);
}

void	free_token(void *content)
{
	t_token	*token;

	token = (t_token *)content;
    free(token->value);
	free(token);
}
