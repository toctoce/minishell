/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 18:31:02 by youngkpa          #+#    #+#             */
/*   Updated: 2023/08/16 16:49:27 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_redir	*create_redir(void)
{
	t_redir	*redir;

	redir = malloc(sizeof(t_redir) * 1);
	check_malloc_error(redir);
	redir->type = RD_NONE;
	redir->value = NULL;
	redir->next = NULL;
	return (redir);
}

void	free_redir(t_redir *redir)
{
	t_redir	*tmp;

	while (redir)
	{
		tmp = redir->next;
		free(redir->value);
		free(redir);
		redir = tmp;
	}
}

int	ft_redirsize(t_redir *redirs)
{
	int	len;

	len = 0;
	while (redirs)
	{
		len++;
		redirs = redirs->next;
	}
	return (len);
}

t_redir	*ft_redirlast(t_redir *redir)
{
	while (ft_redirsize(redir) > 1)
		redir = redir->next;
	return (redir);
}

void	ft_rediradd_back(t_redir **redirs, t_redir *new)
{
	if (!*redirs)
		*redirs = new;
	else
		ft_redirlast(*redirs)->next = new;
}
