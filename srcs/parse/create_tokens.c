/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_tokens.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 18:24:27 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/12 20:34:09 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	create_tokens(t_list **tokens, t_list **dummys, char *line)
{
	t_list	*token;
	t_list	*seek;

	create_dummies(dummys, line); // 더미로 담아버리기~
	while (*dummys)
	{
		print("-------");
		if (!(((t_dummy_info *)(*dummys)->content)->addr))
			print("null");
		if (((t_dummy_info *)(*dummys)->content)->addr)
		{
			print(((t_dummy_info *)(*dummys)->content)->addr);
			ft_putnbr_fd(((t_dummy_info *)(*dummys)->content)->size, 1);
			print("");
		}
		(*dummys) = (*dummys)->next;
	}
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
	return (SUCCESS);
}
