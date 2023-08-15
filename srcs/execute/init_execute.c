/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dohyunki <dohyunki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 22:24:34 by dohyunki          #+#    #+#             */
/*   Updated: 2023/08/11 22:48:21 by dohyunki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/execute.h"

void	set_pipe_cnt(int *cnt_pipe, t_argv *argv)
{
	t_argv	*tmp;
	int		cnt;

	cnt = 0;
	if (!argv)
	{
		*cnt_pipe = 0;
		return ;
	}
	tmp = argv->next;
	while (tmp)
	{
		cnt++;
		tmp = tmp->next;
	}
	*cnt_pipe = cnt;
}

int	set_pipes(int ***pipes, int cnt_pipe)
{
	int	idx;

	*pipes = (int **)malloc(sizeof(int *) * (cnt_pipe + 1));
	if (!(*pipes))
		exit_shell_by_error("malloc failed");
	(*pipes)[cnt_pipe] = NULL;
	idx = 0;
	while (idx < cnt_pipe)
	{
		(*pipes)[idx] = (int *)malloc(sizeof(int) * 2);
		idx++;
	}
	idx = 0;
	while (idx < cnt_pipe)
	{
		if (pipe((*pipes)[idx]) < 0) // pipe로 부모 자식 프로세스간 통신
		{
			ft_error("pipe", strerror(errno), FAIL);
			close_pipes(*pipes, idx);
			return (FAIL);
		}
		idx++;
	}
	return (SUCCESS);
}
