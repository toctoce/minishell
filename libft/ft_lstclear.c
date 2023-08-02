/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youngkpa <youngkpa@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:12:31 by youngkpa          #+#    #+#             */
/*   Updated: 2023/01/10 22:31:55 by youngkpa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*target;

	if (!*lst)
		return ;
	while (*lst)
	{
		target = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(target, del);
	}
	lst = 0;
}
