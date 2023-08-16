/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 16:42:30 by dohyunki          #+#    #+#             */
/*   Updated: 2023/08/16 16:42:30 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	reset_stdin(int fd)
{
	dup2(fd, STDIN_FILENO);
	close(fd);
}

void	reset_stdout(int fd)
{
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

int	set_stdin_redir(t_argv *argv)
{
	int		fd;
	t_redir	*tmp;

	tmp = argv->in;
	if (!tmp)
		return (SUCCESS);
	while (tmp)
	{
		fd = ft_open(tmp->value, RD_IN);
		if (fd < 0)
			return (FAIL);
		tmp = tmp->next;
		if (tmp)
			close(fd);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	return (SUCCESS);
}

int	set_stdout_redir(t_argv *argv)
{
	int		fd;
	t_redir	*tmp;

	tmp = argv->out;
	if (!tmp)
		return (SUCCESS);
	while (tmp)
	{
		if (tmp->type == RD_T_OUT)
			fd = ft_open(tmp->value, RD_T_OUT);
		if (tmp->type == RD_A_OUT)
			fd = ft_open(tmp->value, RD_A_OUT);
		if (fd < 0)
			return (FAIL);
		tmp = tmp->next;
		if (tmp)
			close(fd);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	return (SUCCESS);
}
